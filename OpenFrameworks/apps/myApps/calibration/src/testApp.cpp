#include "testApp.h"
#include "PhotoFrame.h"
#include "ofxCvColorImage.h"
#include "ofxCvGrayscaleImage.h"
#include "ofxEasyGui.h"
#include "Button.h"
#include <vector>
#include <fstream>
#include <cxcore.h>


int camWidth = 320;
int camHeight = 240;
int numOfCapture = 20;
int captureInterval = 1; // in seconds
float squareSize = 2.3; //Set this actual square size
CvSize patternSize;

bool capturing = false;
int currentCaptureNum;
float startCaptureTime;
int view; //0:live camera 1:saved images
bool needCapture;
bool captureButtonPressed = false;
bool detectChessBoard = false;

vector<PhotoFrame*> photoFrames;
vector<ofImage> savedImages(4);
vector<ofRectangle> camPositions(4);
vector<ofVideoGrabber> videoGrabbers(4);
vector<ofxCvColorImage> cvImages(4);
vector<bool> checkboardResults(4);
vector<bool*> cameraSelects(4);
vector<UiButton*> cameraSelectButtons(4);

ofSoundPlayer shutterSnd;
GuiHandler gui;
UiButton* captureButton;
UiButton* detectChessBoardButton;
bool myValue1;
ofxXmlSettings setting;

bool calibrated = false;

//stereo calibration
double M1[3][3], M2[3][3], D1[5], D2[5];
double R[3][3], T[3], E[3][3], F[3][3];
CvMat _M1 = cvMat(3, 3, CV_64F, M1 );
CvMat _M2 = cvMat(3, 3, CV_64F, M2 );
CvMat _D1 = cvMat(1, 5, CV_64F, D1 );
CvMat _D2 = cvMat(1, 5, CV_64F, D2 );
CvMat _R = cvMat(3, 3, CV_64F, R );
CvMat _T = cvMat(3, 1, CV_64F, T );
CvMat _E = cvMat(3, 3, CV_64F, E );
CvMat _F = cvMat(3, 3, CV_64F, F );

//RECTIFICATION
CvMat* mx1 = cvCreateMat( camHeight, camWidth, CV_32F );
CvMat* my1 = cvCreateMat( camHeight, camWidth, CV_32F );
CvMat* mx2 = cvCreateMat( camHeight, camWidth, CV_32F );
CvMat* my2 = cvCreateMat( camHeight, camWidth, CV_32F );
CvMat* disp0 = cvCreateMat( camHeight, camWidth, CV_16S );
CvMat* disp1 = cvCreateMat( camHeight, camWidth, CV_16S );
CvMat* gimg0 = cvCreateMat( camHeight, camWidth, CV_8U );
CvMat* gimg1 = cvCreateMat( camHeight, camWidth, CV_8U );
CvMat* vdisp = cvCreateMat( camHeight, camWidth, CV_8U );
CvMat* pair;
double R1[3][3], R2[3][3], P1[3][4], P2[3][4];
CvMat _R1 = cvMat(3, 3, CV_64F, R1);
CvMat _R2 = cvMat(3, 3, CV_64F, R2);

CvMat _P1 = cvMat(3, 4, CV_64F, P1);
CvMat _P2 = cvMat(3, 4, CV_64F, P2);

//stereo corrrespondences
CvStereoGCState* gcState;
CvStereoBMState* bmState;

string getFileNameOf(int index, int cam = -1){
    string name = ofToString(index) + "-";
    switch (cam) {
        case 0:
            name += "00";
            break;
        case 1:
            name += "10";
            break;
        case 2:
            name += "01";
            break;
        case 3:
            name += "11";
            break;
    }
    name += ".png";

    return name;
}

void generateTextFile(){
    ofstream fout;
    fout.open(ofToDataPath("stereo_calib.txt").c_str());
    fout << patternSize.width << " " << patternSize.height << endl;
    for (int i = 0 ; i < numOfCapture ; i++) {
        for (int cam = 0; cam < 4 ;cam++){
            if (*cameraSelects[cam])
                fout << getFileNameOf(i,cam) << endl;
        }
    }
    fout.close();
}

void startCapture() {
    if (!captureButtonPressed) captureButton->press();
    capturing = true;

    currentCaptureNum = 0;
    if (!detectChessBoard) detectChessBoardButton->press();

    for (int i = 0 ; i < numOfCapture ; i++){
        photoFrames.at(i)->isPhotoTaken = false;
    }
    startCaptureTime = ofGetElapsedTimef();
}

void stopCapture() {
    capturing = false;

    if (captureButtonPressed)
        captureButton->press();
}

bool isAllSelectedCameraCheckboardDetected() {
    for (int cam = 0; cam < 4; cam++){
        if (*cameraSelects[cam] && !checkboardResults[cam])
            return false;
    }
    return true;
}

void calibrateFromSavedCaptures() {
    ofImage ofImg;
    ofxCvColorImage cvImg;

    vector<CvPoint2D32f> temp;
    vector<CvPoint3D32f> objectPoints;
    vector<int> npoints;
    vector<CvPoint2D32f> points[2];
    int count = 0;

    int i, j, cam, N, n;

    n = patternSize.width*patternSize.height;
    temp.resize(n);
    cvImg.allocate(camWidth,camHeight);

    for (i = 0; i < numOfCapture ; i++) {
        for (cam = 0; cam < 4; cam++){
            if (! *cameraSelects[cam]) continue; //skip the image if the camera is not selected

            vector<CvPoint2D32f>& pts = points[cam%2];

            ofImg.loadImage(getFileNameOf(i,cam));
            cvImg.setFromPixels(ofImg.getPixels(), camWidth, camHeight);

            int result = cvFindChessboardCorners(cvImg.getCvImage(),
                                                 patternSize,
                                                 &temp[0],
                                                 &count,
                                                 CV_CALIB_CB_ADAPTIVE_THRESH |
                                                 CV_CALIB_CB_NORMALIZE_IMAGE);

            N = pts.size();
            pts.resize(N + n, cvPoint2D32f(0,0));

            if (result != 1) {
                ofLog(OF_LOG_ERROR, "Only " + ofToString(count) + " points is detected in " + getFileNameOf(i,cam));
                return;
            }

            /*
            cvFindCornerSubPix(cvImg.getCvImage(),
                               &temp[0],
                               count,
                               cvSize(11, 11), //search window
                               cvSize(-1,-1),
                               cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 30, 0.01) );*/

            copy( temp.begin(), temp.end(), pts.begin() + N );
        }
    }

    objectPoints.resize(numOfCapture*n);

    for( i = 0; i < patternSize.height; i++ )
        for( j = 0; j < patternSize.width; j++ )
        objectPoints[i*patternSize.width + j] =
        cvPoint3D32f(i*squareSize, j*squareSize, 0);
    for( i = 1; i < numOfCapture; i++ )
        copy( objectPoints.begin(), objectPoints.begin() + n,
        objectPoints.begin() + i*n );
    npoints.resize(numOfCapture, n);
    N = numOfCapture*n;
    CvMat _objectPoints = cvMat(1, N, CV_32FC3, &objectPoints[0] );
    CvMat _imagePoints1 = cvMat(1, N, CV_32FC2, &points[0][0] );
    CvMat _imagePoints2 = cvMat(1, N, CV_32FC2, &points[1][0] );
    CvMat _npoints = cvMat(1, npoints.size(), CV_32S, &npoints[0] );
    cvSetIdentity(&_M1);
    cvSetIdentity(&_M2);
    cvZero(&_D1);
    cvZero(&_D2);

    // CALIBRATE THE STEREO CAMERAS
    ofLog(OF_LOG_NOTICE, "Running stereo calibration ...");

    cvStereoCalibrate(&_objectPoints,
                      &_imagePoints1,
                      &_imagePoints2, &_npoints,
                      &_M1, &_D1, &_M2, &_D2,
                      cvSize(camWidth,camHeight), &_R, &_T, &_E, &_F,
                      cvTermCriteria(CV_TERMCRIT_ITER+
                                     CV_TERMCRIT_EPS, 100, 1e-5),
                      CV_CALIB_FIX_ASPECT_RATIO +
                      CV_CALIB_SAME_FOCAL_LENGTH );

    ofLog(OF_LOG_NOTICE, "stereo calibration: done");
    fflush(stdout);

    // CALIBRATION QUALITY CHECK
    // because the output fundamental matrix implicitly
    // includes all the output information,
    // we can check the quality of calibration using the
    // epipolar geometry constraint: m2^t*F*m1=0
    vector<CvPoint3D32f> lines[2];
    points[0].resize(N);
    points[1].resize(N);
    _imagePoints1 = cvMat(1, N, CV_32FC2, &points[0][0] );
    _imagePoints2 = cvMat(1, N, CV_32FC2, &points[1][0] );
    lines[0].resize(N);
    lines[1].resize(N);
    CvMat _L1 = cvMat(1, N, CV_32FC3, &lines[0][0]);
    CvMat _L2 = cvMat(1, N, CV_32FC3, &lines[1][0]);
    //Always work in undistorted space
    cvUndistortPoints( &_imagePoints1, &_imagePoints1,
        &_M1, &_D1, 0, &_M1 );
    cvUndistortPoints( &_imagePoints2, &_imagePoints2,
        &_M2, &_D2, 0, &_M2 );
    cvComputeCorrespondEpilines( &_imagePoints1, 1, &_F, &_L1 );
    cvComputeCorrespondEpilines( &_imagePoints2, 2, &_F, &_L2 );
    double avgErr = 0;
    for( i = 0; i < N; i++ )
    {
        double err = fabs(points[0][i].x*lines[1][i].x +
            points[0][i].y*lines[1][i].y + lines[1][i].z)
            + fabs(points[1][i].x*lines[0][i].x +
            points[1][i].y*lines[0][i].y + lines[0][i].z);
        avgErr += err;
    }

    ofLog(OF_LOG_NOTICE, "stereo calibration avg err = " + ofToString(avgErr/(numOfCapture*n)));


    //RECTIFICATION
    cvStereoRectify( &_M1, &_M2, &_D1, &_D2, cvSize(camWidth, camHeight),
                    &_R, &_T,
                    &_R1, &_R2, &_P1, &_P2, 0,
                    0/*CV_CALIB_ZERO_DISPARITY*/ );

    cvInitUndistortRectifyMap(&_M1,&_D1,&_R1,&_P1,mx1,my1);
    cvInitUndistortRectifyMap(&_M2,&_D2,&_R2,&_P2,mx2,my2);

    calibrated = true;

    gcState = cvCreateStereoGCState(16,3);
    bmState = cvCreateStereoBMState();
    bmState->minDisparity = 0;
    bmState->numberOfDisparities = 80;
    bmState->SADWindowSize = 15;
}

void setInitSetting() {
    setting.clear();
    setting.addTag("setting");
    setting.pushTag("setting");

        setting.setValue("framerate",120);

        setting.addTag("stereoPair");
        setting.pushTag("stereoPair");
            setting.addTag("camera");
            setting.pushTag("camera");
                setting.setValue("index",0);
                setting.setValue("captureWidth",320);
                setting.setValue("captureHeight",240);
                setting.setValue("cameraMatrix","");
                setting.setValue("distCoeffs","");
            setting.popTag(); //camera

            setting.addTag("camera");
            setting.pushTag("camera",1);
                setting.setValue("index",1);
                setting.setValue("captureWidth",320);
                setting.setValue("captureHeight",240);
                setting.setValue("cameraMatrix","");
                setting.setValue("distCoeffs","");
            setting.popTag(); //camera

            setting.setValue("rotationMatrix","");
            setting.setValue("translationVector","");
            setting.setValue("essentialMatrix","");
            setting.setValue("fundamentalMatrix","");
        setting.popTag(); //stereoPair

        setting.addTag("stereoPair");
        setting.pushTag("stereoPair",1);
            setting.addTag("camera");
            setting.pushTag("camera");
                setting.setValue("index",2);
                setting.setValue("captureWidth",320);
                setting.setValue("captureHeight",240);
                setting.setValue("cameraMatrix","");
                setting.setValue("distCoeffs","");
            setting.popTag(); //camera

            setting.addTag("camera");
            setting.pushTag("camera",1);
                setting.setValue("index",3);
                setting.setValue("captureWidth",320);
                setting.setValue("captureHeight",240);
                setting.setValue("cameraMatrix","");
                setting.setValue("distCoeffs","");
            setting.popTag(); //camera

            setting.setValue("rotationMatrix","");
            setting.setValue("translationVector","");
            setting.setValue("essentialMatrix","");
            setting.setValue("fundamentalMatrix","");
        setting.popTag(); //stereoPair

    setting.popTag(); //setting

    setting.saveFile("setting.xml");
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);

    if (setting.loadFile("setting.xml")){
        ofLog(OF_LOG_NOTICE,"setting.xml loaded.");
    } else {
        setInitSetting();
        ofLog(OF_LOG_WARNING,"setting.xml not found and created with init settings.");
    }


    ofSetFrameRate(setting.getValue("framerate",120));videoGrabbers[0].listDevices();

    int cam;
    setting.pushTag("setting");
    setting.pushTag("stereoPair");
    setting.pushTag("camera");
    videoGrabbers[0].setDeviceID(setting.getValue("index",0));
    videoGrabbers[0].setUseTexture(false);
    videoGrabbers[0].initGrabber(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    cvImages[0].allocate(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    setting.popTag(); //camera
    setting.pushTag("camera",1);
    videoGrabbers[1].setDeviceID(setting.getValue("index",1));
    videoGrabbers[1].setUseTexture(false);
    videoGrabbers[1].initGrabber(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    cvImages[1].allocate(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    setting.popTag(); //camera
    setting.popTag(); //stereoPair
    setting.pushTag("stereoPair",1);
    setting.pushTag("camera");
    videoGrabbers[2].setDeviceID(setting.getValue("index",2));
    videoGrabbers[2].setUseTexture(false);
    videoGrabbers[2].initGrabber(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    cvImages[2].allocate(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    setting.popTag(); //camera
    setting.pushTag("camera",1);
    videoGrabbers[3].setDeviceID(setting.getValue("index",3));
    videoGrabbers[3].setUseTexture(false);
    videoGrabbers[3].initGrabber(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    cvImages[3].allocate(setting.getValue("captureWidth",320), setting.getValue("captureHeight",240));
    setting.popTag(); //camera
    setting.popTag(); //stereoPair

    for (cam = 0 ; cam < 4 ; cam++){
        camPositions[cam].width = camWidth;
        camPositions[cam].height = camHeight;
    }

    camPositions.at(0).x = 5;
    camPositions.at(0).y = 5;

    camPositions.at(1).x = 5+camWidth;
    camPositions.at(1).y = 5;

    camPositions.at(2).x = 5;
    camPositions.at(2).y = 5+camHeight;

    camPositions.at(3).x = 5+camWidth;
    camPositions.at(3).y = 5+camHeight;


    int gap = 5;
    int w = 20;
    int h = 20;
    PhotoFrame* pf;
    for (int n = 0 ; n < numOfCapture ; n++) {
        pf = new PhotoFrame();
        photoFrames.push_back(pf);
        pf->fileNum = n;
        pf->setPosAndSize(10 + camWidth*2, 5 + (h+gap) * n, w, h);
    }

    //chessboard pattern
    patternSize.width = 8;
    patternSize.height = 6;

    //setup sound
    shutterSnd.loadSound("camera-shutter.mp3");
    shutterSnd.setMultiPlay(true);

    //setup GUI
    GuiPanel* Panel1 = gui.addPanel("controls", 10 + camWidth*2 + w + 20, 5, 200, 250);
    captureButton = Panel1->addButton("capture", 160, 20, "SWITCH", true, 1, &captureButtonPressed);
    detectChessBoardButton = Panel1->addButton("detect chessboard", 160, 20, "SWITCH", true, 2, &detectChessBoard);

    for (cam = 0 ; cam < 4 ; cam++){
        cameraSelects[cam] = new bool(true);
        cameraSelectButtons[cam] = Panel1->addButton("cam "+ofToString(cam), 80, 20, "SWITCH", true, 5+cam, cameraSelects[cam]);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    if (captureButtonPressed and !capturing) {
        startCapture();
    } else if (!captureButtonPressed and capturing) {
        stopCapture();
    }

    int cam;
    for (cam = 0 ; cam < 4 ; cam++){
        videoGrabbers[cam].grabFrame();
    }

    vector<unsigned char*> oriPixels(4);

    view = ( capturing
            or !PhotoFrame::overFrame //no over frame is recorded
            or !PhotoFrame::overFrame->isMouseOver()) ? 0 : 1;

    if (view == 0){
        vector<CvPoint2D32f> temp(patternSize.width*patternSize.height);
        int count = 0;

        for (cam = 0 ; cam < 4 ; cam++){
            if (oriPixels[cam])
                delete oriPixels[cam];

            oriPixels[cam] = videoGrabbers[cam].getPixels();

            cvImages[cam].setFromPixels(oriPixels[cam],camWidth,camHeight);

            if (detectChessBoard && *cameraSelects[cam]){
                checkboardResults[cam] = cvFindChessboardCorners(cvImages[cam].getCvImage(),
                                                                 patternSize,
                                                                 &temp[0],
                                                                 &count,
                                                                 CV_CALIB_CB_ADAPTIVE_THRESH |
                                                                 CV_CALIB_CB_NORMALIZE_IMAGE);

                cvDrawChessboardCorners(cvImages[cam].getCvImage(),
                                        patternSize,
                                        &temp[0],
                                        count,
                                        checkboardResults[cam] );
            }
        }
    }

    needCapture = (capturing
                   && ofGetElapsedTimef() - startCaptureTime >= captureInterval //captureInterval is over
                   && isAllSelectedCameraCheckboardDetected()); //all cameras have checkboard detected

    if (needCapture) {
        ofImage grabImg;
        for (cam = 0 ; cam < 4 ; cam++){
            if (*cameraSelects[cam]){
                string name = getFileNameOf(currentCaptureNum,cam);
                grabImg.setFromPixels(oriPixels[cam],camWidth,camHeight,OF_IMAGE_COLOR);
                grabImg.saveImage(name);
            }
        }
        grabImg.clear();

        photoFrames.at(currentCaptureNum)->isPhotoTaken = true;

        shutterSnd.play();

        startCaptureTime = ofGetElapsedTimef();

        if (++currentCaptureNum >= numOfCapture){ //finished capturing
            stopCapture();
        };
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(200,200,200);
    ofSetColor(255,255,255);
    ofFill();


    int cam;
    int count = 0;

    if (view == 0) { //live view
        for (cam = 0 ; cam < 4 ; cam++){
            if (*cameraSelects[cam]){
                if (calibrated){
                    if (count == 0){
                        cvImages[cam].remap((IplImage*) mx1, (IplImage*) my1);
                    } else if (count == 1){
                        cvImages[cam].remap((IplImage*) mx2, (IplImage*) my2);
                    } else {
                        ofLog(OF_LOG_WARNING,"more than 2 cameras are selected, only the first two is rectified.");
                    }
                }

                cvImages[cam].draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);
                count++;
            }
        }
        if (calibrated){
            ofxCvGrayscaleImage grayImg;
            grayImg.allocate(camWidth,camHeight);

            cvCvtColor(cvImages[0].getCvImage(),gimg0,CV_BGR2GRAY);
            cvCvtColor(cvImages[1].getCvImage(),gimg1,CV_BGR2GRAY);

            if (false){
                cvFindStereoCorrespondenceGC(gimg0, gimg1, disp0, disp1, gcState);
                cvNormalize(disp0, grayImg.getCvImage(), 0, 256, CV_MINMAX);
                cam = 2;
                grayImg.draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);

                cvNormalize(disp1, grayImg.getCvImage(), 0, 255, CV_MINMAX);
                cam = 3;
                grayImg.draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);
            } else {
                cvFindStereoCorrespondenceBM(gimg0, gimg1, disp0, bmState);
                cvNormalize(disp0, grayImg.getCvImage(), 0, 255, CV_MINMAX);
                cam = 2;
                grayImg.draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);
            }

        }
    } else if (view == 1){ //show saved image
        for (cam = 0 ; cam < 4 ; cam++){
            if ( *cameraSelects[cam]
                && savedImages[cam].loadImage(getFileNameOf(PhotoFrame::overFrame->fileNum, cam))) //load saved capture is successful
            {
                if (calibrated){
                    cvImages[cam].setFromPixels(savedImages[cam].getPixels(),camWidth,camHeight);
                    if (count == 0){
                        cvImages[cam].remap((IplImage*) mx1, (IplImage*) my1);
                    } else if (count == 1){
                        cvImages[cam].remap((IplImage*) mx2, (IplImage*) my2);
                    } else {
                        ofLog(OF_LOG_WARNING,"more than 2 cameras are selected, only the first two is rectified.");
                    }

                    cvImages[cam].draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);
                } else {
                    savedImages[cam].draw(camPositions[cam].x, camPositions[cam].y, camPositions[cam].width, camPositions[cam].height);
                }

                count++;
            }
        }
    }

    gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'c') {
        startCapture();
    } else if (key == 'b') {
        calibrateFromSavedCaptures();
    } else if (key == 'q') {
        ofLog(OF_LOG_NOTICE,"minDisparity:"+ofToString(++bmState->minDisparity));
    } else if (key == 'a') {
        ofLog(OF_LOG_NOTICE,"minDisparity:"+ofToString(--bmState->minDisparity));
    } else if (key == 'w') {
        bmState->SADWindowSize+=2;
        ofLog(OF_LOG_NOTICE,"SADWindowSize:"+ofToString(bmState->SADWindowSize));
    } else if (key == 's') {
        if (bmState->SADWindowSize > 5)
            bmState->SADWindowSize-=2;
        ofLog(OF_LOG_NOTICE,"SADWindowSize:"+ofToString(bmState->SADWindowSize));
    } else if (key == 'e') {
        bmState->numberOfDisparities+=16;
        ofLog(OF_LOG_NOTICE,"numberOfDisparities:"+ofToString(bmState->numberOfDisparities));
    } else if (key == 'd') {
        if (bmState->numberOfDisparities > 16)
            bmState->numberOfDisparities-=16;
        ofLog(OF_LOG_NOTICE,"numberOfDisparities:"+ofToString(bmState->numberOfDisparities));
    } else if (key == 'r') {
        bmState->speckleWindowSize+=2;
        ofLog(OF_LOG_NOTICE,"speckleWindowSize:"+ofToString(bmState->speckleWindowSize));
    } else if (key == 'f') {
        if (bmState->speckleWindowSize > 5)
            bmState->speckleWindowSize-=2;
        ofLog(OF_LOG_NOTICE,"speckleWindowSize:"+ofToString(bmState->speckleWindowSize));
    } else if (key == 't') {
        ofLog(OF_LOG_NOTICE,"speckleRange:"+ofToString(++bmState->speckleRange));
    } else if (key == 'g') {
        ofLog(OF_LOG_NOTICE,"speckleRange:"+ofToString(--bmState->speckleRange));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
