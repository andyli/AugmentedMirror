#include "amCamera.h"

amCamera::amCamera(){
    cameraMatrix = cvMat(3, 3, CV_64F, M );
    distCoeffs = cvMat(1, 5, CV_64F, D );

    source = NULL;
}

void amCamera::init() {
    if (!source) source = new amCameraSourceGrabber();

    amCameraSourceGrabber* csg = dynamic_cast<amCameraSourceGrabber*>(source);
    if (csg) {
        csg->index = index;
        csg->captureWidth = captureWidth;
        csg->captureHeight = captureHeight;
    }
    source->init();
}

void amCamera::draw(float x, float y){
    source->draw(x,y);
}

void amCamera::draw(float x, float y, float w, float h) {
    source->draw(x,y,w,h);
}

unsigned char* amCamera::getPixels() {
    return source->getPixels();
}
