#ifndef AMCAMERASOURCE_H
#define AMCAMERASOURCE_H

#include "ofMain.h"

class amCameraSource : public ofBaseHasPixels
{
    public:
        amCameraSource(){}

        virtual void init(){}
        virtual inline void draw(float x, float y){}
        virtual inline void draw(float x, float y, float w, float h){}
        virtual inline void grabFrame(){}
        virtual inline bool isFrameNew(){ return false; }
};

#endif // AMCAMERASOURCE_H
