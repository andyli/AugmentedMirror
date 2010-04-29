#ifndef AMCAMERA_H
#define AMCAMERA_H


#include <vector>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "amCameraSource.h"
#include "amCameraSourceGrabber.h"

class amCamera : public ofBaseHasPixels
{
    public:
        amCameraSource* source;

        CvMat cameraMatrix;
        CvMat distCoeffs;

        amCamera();
        void init();
        int getId() { return id; }
        int getCaptureWidth() { return captureWidth; }
        int getCaptureHeight() { return captureHeight; }
        void draw(float x, float y);
        void draw(float x, float y, float w, float h);
        void grabFrame() { source->grabFrame(); }
        bool isFrameNew() { return source->isFrameNew(); }
        unsigned char* getPixels();

    protected:
        int id;
        int index;
        int captureWidth;
        int captureHeight;

        double M[3][3];
        double D[5];

    friend class amSetting;
};

#endif // AMCAMERA_H
