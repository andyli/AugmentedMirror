#ifndef AMSETTING_H
#define AMSETTING_H

#include <vector>
#include "ofxXmlSettings.h"
#include "amCamera.h"
#include "amCameraPair.h"
#include "amUtil.h"

class amCameraPair;

class amSetting {
    public:
        amCamera* getCameraById(int id);
        vector<amCamera*> cameras;
        amCameraPair* getCameraPairById(int id);
        vector<amCameraPair*> cameraPairs;
        string getFileName() { return fileName; }

        amSetting(string fileName);
        void createNewSetting();
        void saveSetting();

        void setupWindow();

    protected:
        string fileName;
        int frameRate;
        int windowX, windowY;
        int windowWidth, windowHeight;
        ofxXmlSettings xmlSetting;

        void createCamera(int id, int index, int captureWidth, int captureHeight, CvMat cameraMatrix, CvMat distCoeffs);
        void createCameraPair(int id, int cameraId0, int cameraId1, CvMat rotationMatrix, CvMat translationVector, CvMat essentialMatrix, CvMat fundamentalMatrix);


};
#endif
