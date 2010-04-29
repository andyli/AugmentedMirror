#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(24);

    amsetting = new amSetting("amSetting.xml");

    amCamPair = amsetting->cameraPairs[0];
    amCamPair->init();
    amCamPair->enableStereoRectify(true);

    TCP.setup(11999);
}

//--------------------------------------------------------------
void testApp::update(){
    amCamPair->grabFrames();
}

//--------------------------------------------------------------
void testApp::draw(){
    amCamPair->draw(0,0);

    for (int c = 0 ; c < TCP.getNumClients() ; c++){
        int readyStr = 1;
        TCP.receiveRawBytes(c, (char*)&readyStr, 1);
        if (readyStr == 8){
            CvMat* map = amCamPair->getDisparityMap();
            int camW = amCamPair->getCamera0()->getCaptureWidth();
            int camH = amCamPair->getCamera0()->getCaptureHeight();
            ofImage colorImg;
            colorImg.setFromPixels(amCamPair->getCameraPixels(0),camW,camH,OF_IMAGE_COLOR);
            colorImg.resize(camW*0.1,camH*0.1);
            IplImage* rit3dimage = cvCreateImage(cvSize(camW,camH),IPL_DEPTH_32F,3);
            IplImage* rit3dimage_s = cvCreateImage(cvSize(camW*0.1,camH*0.1),IPL_DEPTH_32F,3);


            cvReprojectImageTo3D(map, (CvMat*) rit3dimage, &amCamPair->getDisparityToDepthMatrix());
            cvResize(rit3dimage,rit3dimage_s, CV_INTER_NN);

            TCP.sendRawBytes(c, (char*)rit3dimage_s->imageData, 32*24*3*4);
            TCP.sendRawBytes(c, (char*)colorImg.getPixels(), 32*24*3);

            cvReleaseImage(&rit3dimage);
            cvReleaseImage(&rit3dimage_s);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------file:///home/andy/Desktop/of_preRelease_v0061_linux_FAT/apps/myApps/headTracking/headTracking.cbp

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

