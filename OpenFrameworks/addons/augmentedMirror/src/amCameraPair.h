#ifndef AMCAMERAPAIR_H
#define AMCAMERAPAIR_H

#include <vector>
#include "ofxOpenCv.h"
#include "amSetting.h"
#include "amCamera.h"

class amSetting;

class amCameraPair
{
    public:
        CvMat rotationMatrix;
        CvMat translationVector;
        CvMat essentialMatrix;
        CvMat fundamentalMatrix;

        CvStereoBMState* bmState;

        amCameraPair();
        void init();
        void grabFrames();
        void setCameras(amCamera* cam0, amCamera* cam1);
        bool isFramesNew() { return camera0->isFrameNew() || camera1->isFrameNew(); }
        void draw(float x, float y);
        void draw(float x, float y, float w, float h);
        int getId() { return id; }

        unsigned char* getCameraPixels(int camera);

        amCamera* getCamera0() { return camera0; }
        amCamera* getCamera1() { return camera1; }
        amCamera* getCamera(int num) { return num ? camera1 : camera0; }

        void initStereoRectify();
        bool getStereoRectifyInited() { return stereoRectifyInited; }
        void enableStereoRectify(bool enable);
        bool getStereoRectifyEnabled() {return stereoRectifyEnabled; }

        CvMat getRectificationMatrix0() { return rectificationMatrix0; }
        CvMat getRectificationMatrix1() { return rectificationMatrix1; }
        CvMat getRectificationMatrix(int num) { return num ? rectificationMatrix1 : rectificationMatrix0; }

        CvMat getRectifiedProjectionMatrix0() { return rectifiedProjectionMatrix0; }
        CvMat getRectifiedProjectionMatrix1() { return rectifiedProjectionMatrix1; }
        CvMat getRectifiedProjectionMatrix(int num) { return num ? rectifiedProjectionMatrix1 : rectifiedProjectionMatrix0; }

        CvMat getDisparityToDepthMatrix() {
            if(!stereoRectifyInited)
                initStereoRectify();
            return disparityToDepthMatrix;
        }

        CvMat* getDisparityMap();
        void drawDisparityMap(float x, float y);

    protected:
        int id;
        int cameraId0;
        int cameraId1;

        double R[3][3], T[3], E[3][3], F[3][3];

        amCamera* camera0;
        amCamera* camera1;

        bool stereoRectifyInited;
        bool stereoRectifyEnabled;
        bool stereoRectified;

        bool stereoCorrespondenceFound;

        CvMat rectificationMatrix0;
        CvMat rectificationMatrix1;
        CvMat rectifiedProjectionMatrix0;
        CvMat rectifiedProjectionMatrix1;

        CvMat disparityToDepthMatrix;

        CvMat* undistortRectifyMap0x;
        CvMat* undistortRectifyMap0y;
        CvMat* undistortRectifyMap1x;
        CvMat* undistortRectifyMap1y;

        ofxCvColorImage undistortRectifyImages[2];
        CvMat* disparityMap;
        ofxCvGrayscaleImage tempGrayImages[2];

        void stereoRectifyOnce();
        void findStereoCorrespondenceOnce();

    friend class amSetting;
};

#endif // AMCAMERAPAIR_H
