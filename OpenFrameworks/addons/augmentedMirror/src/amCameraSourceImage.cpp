#include "amCameraSourceImage.h"

void amCameraSourceImage::init() {
    image.loadImage(fileName);
}

void amCameraSourceImage::draw(float x, float y) {
    image.draw(x,y);
}

void amCameraSourceImage::draw(float x, float y, float w, float h) {
    image.draw(x,y,w,h);
}
