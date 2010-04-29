#include "testApp.h"

ofxTouchContourFinder  contourFinder[2];

ofxCvColorImage img[2];
ofxCvGrayscaleImage gImg[2];
ofxTouchFilter*  filter;

ofVideoGrabber vid;

amCameraPair* camPair;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(24);
    amsetting = new amSetting("amSetting.xml");

    camPair = amsetting->getCameraPairById(1);
    camPair->init();
    camPair->enableStereoRectify(true);

    for (int i = 0 ; i < 2 ; i++) {
        img[i].allocate(320,240);
        gImg[i].allocate(320,240);
    }
    filter = new ofxTouchAdaptiveFilter();
    filter->allocate(320,240);
    filter->threshold = 35;

	TCP.setup(11998);
}

//--------------------------------------------------------------
void testApp::update(){
    amCamera* cam;
    camPair->grabFrames();

    for (int i = 0 ; i < 2 ; i++) {
        cam = camPair->getCamera(i);
        img[i].setFromPixels(camPair->getCameraPixels(i),cam->getCaptureWidth(),cam->getCaptureHeight());
        gImg[i] = img[i];
        filter->apply(gImg[i]);
        contourFinder[i].findContours( gImg[i], 1, 40, 2, true );
    }
}


//--------------------------------------------------------------
void testApp::draw(){
    camPair->draw(0,0);
    contourFinder[0].draw(0,0);
    contourFinder[1].draw(320,0);

    float blobsData[6];

    if (contourFinder[0].blobs.size() == 2 && contourFinder[1].blobs.size() == 2){ //=2
        sort(contourFinder[0].blobs.begin(),contourFinder[0].blobs.end(),amUtil::blobIsLeftOf);
        sort(contourFinder[1].blobs.begin(),contourFinder[1].blobs.end(),amUtil::blobIsLeftOf);

        ofxVec3f in, out;
        for(int i = 0 ; i < 2 ; i++){
            in.x = contourFinder[0].blobs[i].center.x;
            in.y = contourFinder[0].blobs[i].center.y;
            in.z = contourFinder[0].blobs[i].center.x - contourFinder[1].blobs[i].center.x;
            out = amUtil::diaparityToDepth(&in, &camPair->getDisparityToDepthMatrix());

            ofDrawBitmapString(ofToString(out.x)+" \n"+ofToString(out.y)+" \n"+ofToString(out.z), 700, 100*(i+1));
            blobsData[3*i] = out.x;
            blobsData[3*i+1] = out.y;
            blobsData[3*i+2] = out.z;
        }
    } else {
        blobsData[0] = blobsData[1] = blobsData[2] = blobsData[3] = blobsData[4] = blobsData[5] = blobsData[6] = -1;
    }

    for (int c = 0 ; c < TCP.getNumClients() ; c++){
        int readyStr = 1;
        TCP.receiveRawBytes(c, (char*)&readyStr, 1);
        if (readyStr == 8){
            TCP.sendRawBytes(c, (char*)blobsData, 6*4);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

