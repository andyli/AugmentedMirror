#include "TestAmSetting.h"
#include "amSetting.h"
#include "amCamera.h"

amSetting* amsetting;

//--------------------------------------------------------------
void TestAmSetting::setup(){
    amsetting = new amSetting("amSetting.xml");

    amCameraPair* amCamPair;
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCamPair->init();
    }
}

//--------------------------------------------------------------
void TestAmSetting::update(){
    amCameraPair* amCamPair;
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCamPair->grabFrames();
    }
}

//--------------------------------------------------------------
void TestAmSetting::draw(){
    amCamera* amCam;
    amCameraPair* amCamPair;
    for (int camPair = 0 ; camPair < amsetting->cameraPairs.size(); camPair++) {
        amCamPair = amsetting->cameraPairs[camPair];
        amCam = amCamPair->getCamera0();
        amCam->draw(0,camPair*amCam->getCaptureHeight(),amCam->getCaptureWidth(),amCam->getCaptureHeight());
        amCam = amCamPair->getCamera1();
        amCam->draw(amCam->getCaptureWidth(),camPair*amCam->getCaptureHeight(),amCam->getCaptureWidth(),amCam->getCaptureHeight());
    }
}

//--------------------------------------------------------------
void TestAmSetting::keyPressed(int key){
    if (key == 's') {
        amsetting->saveSetting();
    }
}

//--------------------------------------------------------------
void TestAmSetting::keyReleased(int key){

}

//--------------------------------------------------------------
void TestAmSetting::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void TestAmSetting::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void TestAmSetting::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void TestAmSetting::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void TestAmSetting::windowResized(int w, int h){

}
