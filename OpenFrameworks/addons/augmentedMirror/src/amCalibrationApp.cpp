#include "amCalibrationApp.h"

ofxMSAShape3D shape3d;

//--------------------------------------------------------------
void amCalibrationApp::setup(){
    //ofSetLogLevel(OF_LOG_NOTICE);

    ofSetVerticalSync(true);

    amsetting = new amSetting("amSetting.xml");

    numOfCapture = 20;
    captureInterval = 2;
    patternSize.width = 8;
    patternSize.height = 6;
    squareSize = 2.457; //cm

    captureTimer = new ofxTimer();
    ofAddListener(captureTimer->TIMER_REACHED,this,&amCalibrationApp::handleTimer);

    capturedCvImages[0].resize(numOfCapture);
    capturedCvImages[1].resize(numOfCapture);
    isCaptured[0].resize(numOfCapture);
    isCaptured[1].resize(numOfCapture);

    bigFont.loadFont("automat.ttf",32);

    //init all the camera pairs
    amCameraPair* amCamPair;
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCamPair->init();
    }

    //setup display images
    amCamPair = amsetting->cameraPairs[0];
    amCamera* cam;
    for (int num = 0 ; num < 2 ; num++) {
        cam = amCamPair->getCamera(num);
        displayImages[num].allocate(cam->getCaptureWidth(), cam->getCaptureHeight());
    }

    //set background color to black
    float* bgColor = ofBgColorPtr();
    bgColor[0] = bgColor[1] = bgColor[2] = 0;

    //prepare captured message
    capturedMsg = "captured!";
    ofRectangle rect = bigFont.getStringBoundingBox(capturedMsg,0,0);
    capturedMsgCX = rect.width*0.5;
    capturedMsgCY = rect.height*0.5;

    ofSetVerticalSync(true);
	centerX = ofGetWidth()/2;
	centerY = ofGetHeight()/2;
	centerZ = 0;
	camera.position(10, 850, 20);
	camera.eye(815,1230,-5320);
	camera.up(0,1,0);
	camera.perspective(140,4/3,0,10000.0f);
	light.directionalLight(255, 0, 0, 1, 0, 0);

	//setup the server to listen on 11999
	TCP.setup(11999);
}

//--------------------------------------------------------------
void amCalibrationApp::update(){
    if (!gui->mIsActive) return;

    amCameraPair* amCamPair;
    amCamera* cam;

    //call all the camera pairs to grab frame
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCamPair->grabFrames();

        //for selected pair, copy the frames to cvImages
        if (camPair == guiPairMatrix->mValue) {
            for (int num = 0 ; num < 2 ; num++) {
                cam = amCamPair->getCamera(num);
                displayImages[num].setFromPixels(cam->getPixels(), cam->getCaptureWidth(), cam->getCaptureHeight());
            }
        }
    }

    //handle capturing
    if (guiCapturePairButton->mValue) {
        amCamPair = getSelectedCameraPair();
        int captureId = getFirstUncheckedId(guiCapturePairMatrix);

        if (captureId == -1) { //if all are captured
            guiCapturePairButton->setValue(false); //stop capturing
            return;
        }

        //detect and draw corners
        vector<CvPoint2D32f> temp(patternSize.width*patternSize.height);
        int count = 0;
        bool checkboardResults[2];
        for (int num = 0 ; num < 2 ; num++) {
            checkboardResults[num] = cvFindChessboardCorners(displayImages[num].getCvImage(),
                                                        patternSize,
                                                        &temp[0],
                                                        &count,
                                                        CV_CALIB_CB_ADAPTIVE_THRESH |
                                                        CV_CALIB_CB_NORMALIZE_IMAGE);

            cvDrawChessboardCorners(displayImages[num].getCvImage(),
                                    patternSize,
                                    &temp[0],
                                    count,
                                    checkboardResults[num] );
        }

        //capture
        if (timeReached && checkboardResults[0] && checkboardResults[1]) {
            ofxCvColorImage* saveImage;
            for (int num = 0 ; num < 2 ; num++) {
                saveImage = &capturedCvImages[num][captureId];
                cam = amCamPair->getCamera(num);
                saveImage->allocate(cam->getCaptureWidth(),cam->getCaptureHeight());
                saveImage->setFromPixels(cam->getPixels(),cam->getCaptureWidth(),cam->getCaptureHeight());
                isCaptured[num][captureId] = true;
            }

            firstCapture = false;
            guiCapturePairMatrix->mBuffer[captureId] = true;
            timeReached = false;
            captureTimer->startTimer();

            if (getFirstUncheckedId(guiCapturePairMatrix) == -1) { //if all are captured
                guiCapturePairButton->setValue(false); //stop capturing
            }
        }
    }
}

int amCalibrationApp::getFirstUncheckedId(ofxGuiMatrix* guiMat) {
    for (int id = 0 ; id < guiMat->mBufferLength ; id++) {
        if (guiMat->mBuffer[id] == false) return id;
    }
    return -1;
}

void amCalibrationApp::calibrateSelectedPair(){
    amCameraPair* amCamPair = getSelectedCameraPair();

    CvMat _M1 = cvMat(3, 3, CV_64F, amCamPair->getCamera0()->cameraMatrix.data.db );
    CvMat _M2 = cvMat(3, 3, CV_64F, amCamPair->getCamera1()->cameraMatrix.data.db );
    CvMat _D1 = cvMat(1, 5, CV_64F, amCamPair->getCamera0()->distCoeffs.data.db );
    CvMat _D2 = cvMat(1, 5, CV_64F, amCamPair->getCamera1()->distCoeffs.data.db );
    CvMat _R = cvMat(3, 3, CV_64F, amCamPair->rotationMatrix.data.db );
    CvMat _T = cvMat(3, 1, CV_64F, amCamPair->translationVector.data.db );
    CvMat _E = cvMat(3, 3, CV_64F, amCamPair->essentialMatrix.data.db );
    CvMat _F = cvMat(3, 3, CV_64F, amCamPair->fundamentalMatrix.data.db );

    ofxCvColorImage* cvImg;
    ofxCvGrayscaleImage cvGrayImg;
    cvGrayImg.allocate(capturedCvImages[0][0].width,capturedCvImages[0][0].height);

    vector<CvPoint2D32f> temp;
    vector<CvPoint3D32f> objectPoints;
    vector<int> npoints;
    vector<CvPoint2D32f> points[2];
    int count = 0;

    int i, j, cam, N, n;

    n = patternSize.width*patternSize.height;
    temp.resize(n);
    for (i = 0; i < numOfCapture ; i++) {
        for (cam = 0; cam < 2; cam++){
            vector<CvPoint2D32f>& pts = points[cam%2];
            cvImg = &capturedCvImages[cam][i];
            int result = cvFindChessboardCorners(cvImg->getCvImage(),
                                                 patternSize,
                                                 &temp[0],
                                                 &count,
                                                 CV_CALIB_CB_ADAPTIVE_THRESH |
                                                 CV_CALIB_CB_NORMALIZE_IMAGE);

            N = pts.size();
            pts.resize(N + n, cvPoint2D32f(0,0));

            if (result != 1) {
                ofLog(OF_LOG_ERROR, "Only " + ofToString(count) + " points is detected in " + ofToString(i) + " of camera" + ofToString(cam));
                return;
            }

            //cvFindCornerSubPix can make the points more accurate
            cvGrayImg = *cvImg;
            cvFindCornerSubPix(cvGrayImg.getCvImage(),
                               &temp[0],
                               count,
                               cvSize(5, 5), //search window
                               cvSize(-1,-1),
                               cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 30, 0.01) );

            copy( temp.begin(), temp.end(), pts.begin() + N );
        }
    }

    //cvGrayImg is only used for cvFindCornerSubPix, so we can clear it now
    cvGrayImg.clear();

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
                      cvSize(cvImg->width,cvImg->height), &_R, &_T, &_E, &_F,
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

    string errStr = ofToString(avgErr/(numOfCapture*n),2);
    ofLog(OF_LOG_NOTICE, "stereo calibration avg err = " + errStr);
    guiCalibratePairButton->mParamName = "calibrate (avg err:" + errStr + ")";

    //printf("%f %f %f %f %f %f %f %f %f \n",_M1.data.db[0],_M1.data.db[1],_M1.data.db[2],_M1.data.db[3],_M1.data.db[4],_M1.data.db[5],_M1.data.db[6],_M1.data.db[7],_M1.data.db[8],_M1.data.db[9]);
    //printf("%f %f %f %f %f %f %f %f %f \n",amCamPair->getCamera0()->cameraMatrix.data.db[0],amCamPair->getCamera0()->cameraMatrix.data.db[1],amCamPair->getCamera0()->cameraMatrix.data.db[2],amCamPair->getCamera0()->cameraMatrix.data.db[3],amCamPair->getCamera0()->cameraMatrix.data.db[4],amCamPair->getCamera0()->cameraMatrix.data.db[5],amCamPair->getCamera0()->cameraMatrix.data.db[6],amCamPair->getCamera0()->cameraMatrix.data.db[7],amCamPair->getCamera0()->cameraMatrix.data.db[8],amCamPair->getCamera0()->cameraMatrix.data.db[9]);
}

//--------------------------------------------------------------
void amCalibrationApp::draw(){
    static int paddingTop = 240;
    static int camDisplayWidth = 320*0.6;
    static int camDisplayHeight = 240*0.6;

    amCamera* amCam;
    amCameraPair* amCamPair;
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCam = amCamPair->getCamera0();

        //display the cameras side by side
        if (guiCapturePairButton->mValue && camPair == guiPairMatrix->mValue) {
            displayImages[0].draw(5,
                                  paddingTop+20+camPair*(camDisplayHeight+20),
                                  camDisplayWidth,
                                  camDisplayHeight);
            displayImages[1].draw(5+camDisplayWidth,
                                  paddingTop+20+camPair*(camDisplayHeight+20),
                                  camDisplayWidth,
                                  camDisplayHeight);

            if (guiCapturePairButton->mValue && !timeReached) {
                if (!firstCapture){
                    //camera flash!
                    ofEnableAlphaBlending();
                    ofFill();
                    ofSetColor(255,255,255,200-captureTimer->getProgress()*200);
                    ofRect(5,
                           paddingTop+20+camPair*(camDisplayHeight+20),
                           camDisplayWidth*2,
                           camDisplayHeight);
                    ofDisableAlphaBlending();

                    //captured message
                    int msgPosX = 5+camDisplayWidth-capturedMsgCX;
                    int msgPosY = paddingTop+camDisplayHeight*0.5+camPair*(camDisplayHeight+20)+capturedMsgCY*2;
                    ofSetColor(0,0,0);
                    bigFont.drawString(capturedMsg, msgPosX+2, msgPosY+2);
                    ofSetColor(255,255,255);
                    bigFont.drawString(capturedMsg, msgPosX, msgPosY );
                }
            }
        } else {
            amCamPair->draw(5,
                            paddingTop+20+camPair*(camDisplayHeight+20),
                            camDisplayWidth*2,
                            camDisplayHeight);
        }
        ofSetColor(255,255,255);
        //place a label on top of the displays
        ofDrawBitmapString("amCameraPair id: "+ofToString(amCamPair->getId()),
                           5,
                           paddingTop+15+camPair*(camDisplayHeight+20));
    }

    //if the "show disparity" button is checked
    if (guiShowDisparityButton->mValue) {
        getSelectedCameraPair()->drawDisparityMap(amCam->getCaptureWidth(),10);
        renderDisparityMap(getSelectedCameraPair());
    }

    //glEnable(GL_DEPTH_TEST);

    //glDisable(GL_DEPTH_TEST);
}

void amCalibrationApp::renderDisparityMap(amCameraPair* camPair) {
    CvMat* map = camPair->getDisparityMap();
    int camW = camPair->getCamera0()->getCaptureWidth();
    int camH = camPair->getCamera0()->getCaptureHeight();
    ofImage colorImg;
    colorImg.setFromPixels(camPair->getCameraPixels(0),camW,camH,OF_IMAGE_COLOR);
    colorImg.resize(camW*0.1,camH*0.1);
    IplImage* rit3dimage = cvCreateImage(cvSize(camW,camH),IPL_DEPTH_32F,3);
    IplImage* rit3dimage_s = cvCreateImage(cvSize(camW*0.1,camH*0.1),IPL_DEPTH_32F,3);
    //cvSet(rit3dimage, cvScalar(0, 0, 0));

    for (int c = 0 ; c < TCP.getNumClients() ; c++){
        int readyStr = 1;
        TCP.receiveRawBytes(c, (char*)&readyStr, 1);
        if (readyStr == 8){
            cvReprojectImageTo3D(map, (CvMat*) rit3dimage, &camPair->getDisparityToDepthMatrix());
            cvResize(rit3dimage,rit3dimage_s, CV_INTER_NN);

            //((float *)(rit3dimage_s->imageData + 10*rit3dimage_s->widthStep))[10*rit3dimage_s->nChannels + 0] = 10;

            TCP.sendRawBytes(c, (char*)rit3dimage_s->imageData, 32*24*3*4);
            TCP.sendRawBytes(c, (char*)colorImg.getPixels(), 32*24*3);
            //ofLog(OF_LOG_NOTICE,ofToString(c)+ofToString(readyStr)+ofToString(ofRandom(0,5)));
        }

        //ofLog(OF_LOG_ERROR, ofToString(int(((char*)colorImg.getPixels())[0])));
        //if (!TCP.isClientConnected(c)) TCP.
    }
/*
    int i,j;
    //ofxCvColorImage img;
    //img.allocate(camW,camH);
    //img.set(0);
    //unsigned char * pixels = img.getPixels();

    CvScalar s;
    //shape3d.begin(GL_TRIANGLE_STRIP);

    float min[3], max[3];

    camera.place();
    glEnable(GL_DEPTH_TEST);
    //ofxMaterialSpecular(120, 120, 120); //how much specular light will be reflect by the surface
	//ofxMaterialShininess(50); //how concentrated the reflexion will be (between 0 and 128
    //ofxLightsOn();

    int posX,posY;
    posX = mouseX-320;
    posY = mouseY-15;
    ofxVec3f pt;
    for (i = 0 ; i < camW ; i++) {
        for (j = 0 ; j <camH ; j++) {
            //s = cvGet2D(rit3dimage, j,i); // get the (i,j) pixel value

            //pt.x = -s.val[0];
            //pt.y = -s.val[1];
            //pt.z = s.val[2];

            pt.x = ((float *)(rit3dimage->imageData + j*rit3dimage->widthStep))[i*rit3dimage->nChannels + 0];
            pt.y = ((float *)(rit3dimage->imageData + j*rit3dimage->widthStep))[i*rit3dimage->nChannels + 1];
            pt.z = ((float *)(rit3dimage->imageData + j*rit3dimage->widthStep))[i*rit3dimage->nChannels + 2];

            pt.x *= -1;
            pt.y *= -1;

            if (pt.z>-200){
                int index = (j*camW+i)*3;//(i*camW+j)*3;
                ofSetColor(colors[index],colors[index+1],colors[index+2]);
                //ofxBox(pt,1);
                ofxSphere(pt,0.5);
            }
        }
    }

    camera.remove();
    glDisable(GL_DEPTH_TEST);
    //ofxLightsOff();

    if (posX >= 0 && posX < 320 && posY >= 0 && posY < 240) {
        s = cvGet2D(rit3dimage, posY, posX);
        pt.x = s.val[0];
        pt.y = s.val[1];
        pt.z = s.val[2];

        ofSetColor(255,255,255);
        ofRect(320+posX,10+posY,5,5);
        ofDrawBitmapString("0:"+ofToString(pt.x)+"\n1:"+ofToString(pt.y)+"\n2:"+ofToString(pt.z)+"\ndist:"+ofToString(pt.distance(ofxVec3f(0,0,0))),
                           325+posX,
                           15+posY);

        s = cvGet2D(map, posY, posX);

        ofDrawBitmapString(ofToString(s.val[0]), 500, 500);
    }

    ofDrawBitmapString("Camera\nx:"+ofToString(camera.getPosition().x)+
                       "\ny:"+ofToString(camera.getPosition().y)+
                       "\nz:"+ofToString(camera.getPosition().z)+
                       "\ndirX:"+ofToString(camera.getDir().x)+
                       "\ndirY:"+ofToString(camera.getDir().y)+
                       "\ndirZ:"+ofToString(camera.getDir().z)+
                       "\neyeX"+ofToString(camera.getEye().x)+
                       "\neyeY:"+ofToString(camera.getEye().y)+
                       "\neyeZ:"+ofToString(camera.getEye().z)+
                       "\nupX"+ofToString(camera.getUp().x)+
                       "\nupY:"+ofToString(camera.getUp().y)+
                       "\nupZ:"+ofToString(camera.getUp().z),
                       10,10);
*/
    cvReleaseImage(&rit3dimage);
    cvReleaseImage(&rit3dimage_s);
}

void amCalibrationApp::setupGui() {
    int guiId = 0;

    ofxGuiPanel	*guiPanel = gui->addPanel(0, "", 10, 20, 12, OFXGUI_PANEL_SPACING);
    guiPairMatrix = guiPanel->addMatrix(guiId++, "cameraPair", 20*amsetting->cameraPairs.size(), 20, amsetting->cameraPairs.size(), 1, 0, kofxGui_Button_Trigger, 2);
    guiCapturePairButton = guiPanel->addButton(guiId++, "capture", 10, 10, kofxGui_Button_Off, kofxGui_Button_Switch, "");
    guiCapturePairMatrix = guiPanel->addMatrix(guiId++, "captures", 200, 40, 10, numOfCapture/10, 0, kofxGui_Button_Switch, 2);
    guiCalibratePairButton = guiPanel->addButton(guiId++, "calibrate", 10, 10, kofxGui_Button_Off, kofxGui_Button_Trigger, "");
    guiEnableRectifyButton = guiPanel->addButton(guiId++, "enable rectify", 10, 10, kofxGui_Button_Off, kofxGui_Button_Switch, "");
    guiShowDisparityButton = guiPanel->addButton(guiId++, "show disparity", 10, 10, kofxGui_Button_Off, kofxGui_Button_Switch, "");
    guiSaveSettingButton = guiPanel->addButton(guiId++, "save to "+amsetting->getFileName(), 10, 10, kofxGui_Button_Off, kofxGui_Button_Trigger, "");

    gui->forceUpdate(false);
	gui->activate(true);

	//delete mover;
}

void amCalibrationApp::handleTimer(ofEventArgs &args) {
    timeReached = true;
}

void amCalibrationApp::handleGui(int parameterId, int task, void* data, int length) {
    if (!gui->mIsActive) return;

    if (parameterId == guiPairMatrix->mParamId) {
        //clear the capture matrix
        for (int id = 0 ; id < guiCapturePairMatrix->mBufferLength ; id++) {
            guiCapturePairMatrix->mBuffer[id] = false;
            isCaptured[0][id] = false;
        }

        //clear the previous calibration result
        guiCalibratePairButton->mParamName = "calibrate";

        //stop capturing
        guiCapturePairButton->setValue(false);

        //setup display images
        amCameraPair* amCamPair = getSelectedCameraPair();
        amCamera* cam;
        for (int num = 0 ; num < 2 ; num++) {
            cam = amCamPair->getCamera(num);
            displayImages[num].allocate(cam->getCaptureWidth(), cam->getCaptureHeight());
        }

    } else if (parameterId == guiCapturePairMatrix->mParamId) {

    } else if (parameterId == guiEnableRectifyButton->mParamId) {
        //you cannot enable rectify when capturing...
        if (guiCapturePairButton->mValue) {
            guiEnableRectifyButton->mValue = false;
        }

        for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
            amsetting->cameraPairs[camPair]->enableStereoRectify(guiEnableRectifyButton->mValue);
        }
    } else if (parameterId == guiCapturePairButton->mParamId) {
        if (guiCapturePairButton->mValue) {
            firstCapture = true;
            timeReached = false;

            //disable rectify
            guiEnableRectifyButton->mValue = false;
            amsetting->cameraPairs[0]->enableStereoRectify(false);
            amsetting->cameraPairs[1]->enableStereoRectify(false);

            //start the timer
            captureTimer->setup(captureInterval,false);
        } else {
            captureTimer->stopTimer();
        }
    } else if (parameterId == guiCalibratePairButton->mParamId) {
        if (guiCalibratePairButton->mValue){
            //if not captured require number of image, don't calibrate
            for (int num = 0 ; num < numOfCapture ; num++){
                if (!(isCaptured[0][num] && isCaptured[1][num])) return;
            }
            calibrateSelectedPair();
        }
    } else if (parameterId == guiSaveSettingButton->mParamId) {
        if (guiSaveSettingButton->mValue) {
            amsetting->saveSetting();
            ofLog(OF_LOG_NOTICE,"setting saved!");
        }
    }

    //ofLog(OF_LOG_ERROR,ofToString(parameterId)+" "+ofToString(task));
    //ofLog(OF_LOG_ERROR,ofToString(kofxGui_Set_Cell)+" "+ofToString(kofxGui_Set_Int));
}

//--------------------------------------------------------------
void amCalibrationApp::keyPressed(int key){
    switch (key) {
        case 'f':
            //amsetting->setupWindow();
            break;
    }

    CvStereoBMState* bmState = getSelectedCameraPair()->bmState;

    if (key == 'q') {
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
    } else if (key == 'i') {
        camera.moveLocal(0,0,10);
    } else if (key == 'j') {
        camera.moveLocal(10,0,0);
    } else if (key == 'l') {
        camera.moveLocal(-10,0,0);
    } else if (key == 'k') {
        camera.moveLocal(0,0,-10);
    } else if (key == 'y') {
        camera.moveLocal(0,10,0);
    } else if (key == 'h') {
        camera.moveLocal(0,-10,0);
    } else if (key == 'u') {
        camera.rotate(ofxVec3f(0,1,0),5);
    } else if (key == 'o') {
        camera.rotate(ofxVec3f(0,1,0),-5);
    }
}

//--------------------------------------------------------------
void amCalibrationApp::keyReleased(int key){

}

//--------------------------------------------------------------
void amCalibrationApp::mouseMoved(int x, int y ){
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void amCalibrationApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void amCalibrationApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void amCalibrationApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void amCalibrationApp::windowResized(int w, int h){

}
