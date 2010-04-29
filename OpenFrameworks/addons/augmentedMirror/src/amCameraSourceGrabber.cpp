#include "amCameraSourceGrabber.h"

void amCameraSourceGrabber::init() {
    videoGrabber.setDeviceID(index);
    videoGrabber.initGrabber(captureWidth,captureHeight);
}

void amCameraSourceGrabber::draw(float x, float y) {
    videoGrabber.draw(x,y);
}

void amCameraSourceGrabber::draw(float x, float y, float w, float h) {
    videoGrabber.draw(x,y,w,h);
}

void amCameraSourceGrabber::grabFrame() {
    videoGrabber.grabFrame();
}

bool amCameraSourceGrabber::isFrameNew() {
    return videoGrabber.isFrameNew();
}

unsigned char* amCameraSourceGrabber::getPixels() {
    return videoGrabber.getPixels();
}
