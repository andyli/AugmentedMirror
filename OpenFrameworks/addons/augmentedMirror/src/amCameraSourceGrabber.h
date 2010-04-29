#ifndef AMCAMERASOURCEGRABBER_H
#define AMCAMERASOURCEGRABBER_H

#include "ofMain.h"
#include "amCameraSource.h"


class amCameraSourceGrabber : public amCameraSource
{
    public:
        amCameraSourceGrabber(){};
        virtual void init();
        virtual inline void draw(float x, float y);
        virtual inline void draw(float x, float y, float w, float h);
        virtual inline void grabFrame();
        virtual inline bool isFrameNew();
        virtual unsigned char* getPixels();

        ofVideoGrabber videoGrabber;
        int index;
        int captureWidth;
        int captureHeight;
};

#endif // AMCAMERASOURCEGRABBER_H
