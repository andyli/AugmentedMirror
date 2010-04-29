#ifndef AMCAMERASOURCEGRABBER_H
#define AMCAMERASOURCEGRABBER_H

#include "ofMain.h"
#include "amCameraSource.h"


class amCameraSourceImage : public amCameraSource
{
    public:
        amCameraSourceImage(){};
        virtual void init();
        virtual inline void draw(float x, float y);
        virtual inline void draw(float x, float y, float w, float h);
        virtual inline void grabFrame(){}
        virtual inline bool isFrameNew(){return false;}

        ofImage image;
        string fileName;
};

#endif // AMCAMERASOURCEGRABBER_H
