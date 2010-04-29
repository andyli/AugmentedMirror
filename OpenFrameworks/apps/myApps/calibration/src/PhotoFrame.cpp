#include "PhotoFrame.h"

PhotoFrame* PhotoFrame::overFrame;

void PhotoFrame::setup() {
    enableMouseEvents();

    color.r = color.g = color.b = 180;
    colorMouseOver.r = colorMouseOver.g = colorMouseOver.b = 150;

    colorPhotoTaken.r = colorPhotoTaken.b = 150;
    colorPhotoTaken.g = 255;

    isPhotoTaken = false;
}

void PhotoFrame::draw() {
    ofFill();

    if(isMouseOver()){
        ofSetColor(colorMouseOver.r, colorMouseOver.g, colorMouseOver.b, colorMouseOver.a);
    } else if (isPhotoTaken){
        ofSetColor(colorPhotoTaken.r, colorPhotoTaken.g, colorPhotoTaken.b, colorPhotoTaken.a);
    } else {
        ofSetColor(color.r, color.g, color.b, color.a);
    }


    ofRect(x, y, width, height);
}

void PhotoFrame::onRollOver(int x, int y) {
    PhotoFrame::overFrame = this;
}
