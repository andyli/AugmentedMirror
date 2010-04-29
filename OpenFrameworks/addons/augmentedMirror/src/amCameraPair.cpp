#include "amCameraPair.h"

amCameraPair::amCameraPair() {
    rotationMatrix = cvMat(3, 3, CV_64F, R );
    translationVector = cvMat(3, 1, CV_64F, T );
    essentialMatrix = cvMat(3, 3, CV_64F, E );
    fundamentalMatrix = cvMat(3, 3, CV_64F, F );

    stereoRectifyInited = false;
    stereoRectifyEnabled = false;
    stereoRectified = false;

    stereoCorrespondenceFound = false;

    bmState = cvCreateStereoBMState();
    bmState->minDisparity = 0;
    bmState->numberOfDisparities = 80;
    bmState->SADWindowSize = 15;
}

void amCameraPair::init() {
    camera0->init();
    camera1->init();
}

void amCameraPair::grabFrames() {
    camera0->grabFrame();
    camera1->grabFrame();

    stereoRectified = stereoRectified && !isFramesNew();
    stereoCorrespondenceFound = stereoCorrespondenceFound && !isFramesNew();
}

void amCameraPair::setCameras(amCamera* cam0, amCamera* cam1){
    if (cam0->getCaptureWidth() != cam1->getCaptureWidth() || cam0->getCaptureHeight() != cam1->getCaptureHeight()) {
        ofLog(OF_LOG_ERROR, "amCameraPair: Cameras of a pair must have same captureWidth and captureHeight.");
        return;
    }

    camera0 = cam0;
    camera1 = cam1;
    cameraId0 = camera0->getId();
    cameraId1 = camera1->getId();

    int camWidth = camera0->getCaptureWidth();
    int camHeight = camera0->getCaptureHeight();
    tempGrayImages[0].allocate(camWidth, camHeight);
    tempGrayImages[1].allocate(camWidth, camHeight);
    disparityMap = cvCreateMat( camHeight, camWidth, CV_16S );
}

void amCameraPair::draw(float x, float y){
    if (stereoRectifyEnabled) {
        stereoRectifyOnce();
        undistortRectifyImages[0].draw(x,y);
        undistortRectifyImages[1].draw(x+camera0->getCaptureWidth(),y);
    } else {
        camera0->draw(x,y);
        camera1->draw(x+camera0->getCaptureWidth(),y);
    }
}

void amCameraPair::draw(float x, float y, float w, float h) {
    int width = w*0.5;

    if (stereoRectifyEnabled) {
        stereoRectifyOnce();
        undistortRectifyImages[0].draw(x,y,width,h);
        undistortRectifyImages[1].draw(x+width,y,width,h);
    } else {
        camera0->draw(x,y,width,h);
        camera1->draw(x+width,y,width,h);
    }
}

void amCameraPair::initStereoRectify() {
    int camWidth = camera0->getCaptureWidth();
    int camHeight = camera0->getCaptureHeight();

    CvMat* mx1 = cvCreateMat( camHeight, camWidth, CV_32F );
    CvMat* my1 = cvCreateMat( camHeight, camWidth, CV_32F );
    CvMat* mx2 = cvCreateMat( camHeight, camWidth, CV_32F );
    CvMat* my2 = cvCreateMat( camHeight, camWidth, CV_32F );

    double R1[3][3], R2[3][3], P1[3][4], P2[3][4];
    CvPoint3D32f Q[4][4];
    CvMat _R1 = cvMat(3, 3, CV_64F, R1);
    CvMat _R2 = cvMat(3, 3, CV_64F, R2);
    CvMat _P1 = cvMat(3, 4, CV_64F, P1);
    CvMat _P2 = cvMat(3, 4, CV_64F, P2);
    CvMat* _Q = cvCreateMat(4, 4, CV_32F);

    cvStereoRectify(&camera0->cameraMatrix, &camera1->cameraMatrix,
                    &camera0->distCoeffs, &camera1->distCoeffs,
                    cvSize(camWidth, camHeight),
                    &rotationMatrix, &translationVector,
                    &_R1, &_R2, &_P1, &_P2, _Q,
                    0/*CV_CALIB_ZERO_DISPARITY*/ );

    cvInitUndistortRectifyMap(&camera0->cameraMatrix,
                              &camera0->distCoeffs,
                              &_R1,
                              &_P1,
                              mx1,my1);
    cvInitUndistortRectifyMap(&camera1->cameraMatrix,
                              &camera1->distCoeffs,
                              &_R2,
                              &_P2,
                              mx2,my2);

    rectificationMatrix0 = _R1;
    rectificationMatrix1 = _R2;
    rectifiedProjectionMatrix0 = _P1;
    rectifiedProjectionMatrix1 = _P2;
    disparityToDepthMatrix = *_Q;

    undistortRectifyImages[0].allocate(camWidth,camHeight);
    undistortRectifyImages[1].allocate(camWidth,camHeight);

    undistortRectifyMap0x = mx1;
    undistortRectifyMap0y = my1;
    undistortRectifyMap1x = mx2;
    undistortRectifyMap1y = my2;

    /*cvReleaseMat(&mx1);
    cvReleaseMat(&my1);
    cvReleaseMat(&mx2);
    cvReleaseMat(&my2);*/
    //cvReleaseMat(&_Q);

    stereoRectifyInited = true;
}

void amCameraPair::enableStereoRectify(bool enable) {
    if (enable && !stereoRectifyInited) initStereoRectify();

    if (stereoRectifyEnabled != enable) {
        stereoRectifyEnabled = enable;
        stereoCorrespondenceFound = false;
    }
}

void amCameraPair::stereoRectifyOnce() {
    if (stereoRectified) return;

    undistortRectifyImages[0].setFromPixels(camera0->getPixels(),camera0->getCaptureWidth(),camera0->getCaptureHeight());
    undistortRectifyImages[0].remap((IplImage*) undistortRectifyMap0x, (IplImage*) undistortRectifyMap0y);
    undistortRectifyImages[1].setFromPixels(camera1->getPixels(),camera1->getCaptureWidth(),camera1->getCaptureHeight());
    undistortRectifyImages[1].remap((IplImage*) undistortRectifyMap1x, (IplImage*) undistortRectifyMap1y);

    stereoRectified = true;
}

void amCameraPair::findStereoCorrespondenceOnce() {
    if (stereoCorrespondenceFound) return;

    if (stereoRectifyEnabled) {
        stereoRectifyOnce();

        cvCvtColor(undistortRectifyImages[0].getCvImage(),tempGrayImages[0].getCvImage(),CV_BGR2GRAY);
        cvCvtColor(undistortRectifyImages[1].getCvImage(),tempGrayImages[1].getCvImage(),CV_BGR2GRAY);
    } else {
        tempGrayImages[0].setFromPixels(camera0->getPixels(),camera0->getCaptureWidth(),camera0->getCaptureHeight());
        tempGrayImages[1].setFromPixels(camera1->getPixels(),camera1->getCaptureWidth(),camera1->getCaptureHeight());
    }

    tempGrayImages[0].flagImageChanged();
    tempGrayImages[1].flagImageChanged();

    cvFindStereoCorrespondenceBM(tempGrayImages[0].getCvImage(), tempGrayImages[1].getCvImage(), disparityMap, bmState);


    IplImage* m_pDisparityMap = cvCreateImage( cvSize(camera0->getCaptureWidth(),camera0->getCaptureHeight()), IPL_DEPTH_16S, 1 );

    cvConvertScale( disparityMap, m_pDisparityMap, 1.0/16, 0 );

    cvCopyImage(m_pDisparityMap,disparityMap);
    cvReleaseImage(&m_pDisparityMap);


    stereoCorrespondenceFound = true;
}

CvMat* amCameraPair::getDisparityMap() {
    findStereoCorrespondenceOnce();
    return disparityMap;
}

void amCameraPair::drawDisparityMap(float x, float y) {
    ofxCvGrayscaleImage* tempG = new ofxCvGrayscaleImage();
    tempG->allocate(camera0->getCaptureWidth(),camera0->getCaptureHeight());

    findStereoCorrespondenceOnce();

    cvNormalize(disparityMap, tempG->getCvImage(), 0, 255, CV_MINMAX);
    tempG->flagImageChanged();
    tempG->draw(x,y);
    tempG->clear();
}

unsigned char* amCameraPair::getCameraPixels(int camera) {
    if (stereoRectifyEnabled) {
        stereoRectifyOnce();
        return undistortRectifyImages[camera].getPixels();
    } else {
        return getCamera(camera)->getPixels();
    }
}
