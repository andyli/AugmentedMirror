#include "amSetting.h"

amSetting::amSetting(string fileName) {
    this->fileName = fileName;
    bool loadSuccess = xmlSetting.loadFile(fileName);
    if(!loadSuccess) {
        createNewSetting();
    }

    xmlSetting.pushTag("setting");

        frameRate = xmlSetting.getValue("framerate",60);
        windowX = xmlSetting.getValue("windowX", 0);
        windowY = xmlSetting.getValue("windowY", 0);
        windowWidth = xmlSetting.getValue("windowWidth", 768);
        windowHeight = xmlSetting.getValue("windowHeight", 1024);

        /* camera */
        for (int cam = 0 ; cam < xmlSetting.getNumTags("camera") ; cam++) {
            xmlSetting.pushTag("camera",cam);
            createCamera(xmlSetting.getValue("id",cam),
                         xmlSetting.getValue("index",cam),
                         xmlSetting.getValue("captureWidth",320),
                         xmlSetting.getValue("captureHeight",240),
                         amUtil::stringToCvMat(&xmlSetting.getValue("cameraMatrix",""),3,3,CV_64F),
                         amUtil::stringToCvMat(&xmlSetting.getValue("distCoeffs",""),1,5,CV_64F));
            xmlSetting.popTag(); //camera
        }

        /* cameraPair */
        for (int sp = 0 ; sp < xmlSetting.getNumTags("cameraPair") ; sp++) {
            xmlSetting.pushTag("cameraPair",sp);
            createCameraPair(xmlSetting.getValue("id",sp),
                             xmlSetting.getValue("cameraId0",sp*2),
                             xmlSetting.getValue("cameraId1",sp*2),
                             amUtil::stringToCvMat(&xmlSetting.getValue("rotationMatrix",""),3,3,CV_64F),
                             amUtil::stringToCvMat(&xmlSetting.getValue("translationVector",""),3,1,CV_64F),
                             amUtil::stringToCvMat(&xmlSetting.getValue("essentialMatrix",""),3,3,CV_64F),
                             amUtil::stringToCvMat(&xmlSetting.getValue("fundamentalMatrix",""),3,3,CV_64F));
            xmlSetting.popTag(); //cameraPair
        }

    xmlSetting.popTag(); //setting
}

void amSetting::createNewSetting() {
    xmlSetting.clear();
    xmlSetting.addTag("setting");
    xmlSetting.pushTag("setting");

        xmlSetting.setValue("framerate",60);
        xmlSetting.setValue("windowX", 0);
        xmlSetting.setValue("windowY", 0);
        xmlSetting.setValue("windowWidth", 768);
        xmlSetting.setValue("windowHeight", 1024);


        /* camera */
        for (int cam = 0 ; cam < 4 ; cam++) {
            xmlSetting.addTag("camera");
            xmlSetting.pushTag("camera",cam);
                xmlSetting.setValue("id",cam);
                xmlSetting.setValue("index",cam);
                xmlSetting.setValue("captureWidth",320);
                xmlSetting.setValue("captureHeight",240);
                xmlSetting.setValue("cameraMatrix","");
                xmlSetting.setValue("distCoeffs","");
            xmlSetting.popTag(); //camera
        }

        /* cameraPair */
        for (int sp = 0 ; sp < 2 ; sp++) {
            xmlSetting.addTag("cameraPair");
            xmlSetting.pushTag("cameraPair",sp);
                xmlSetting.setValue("id",sp);
                xmlSetting.setValue("cameraId0",sp*2);
                xmlSetting.setValue("cameraId1",sp*2+1);
                xmlSetting.setValue("rotationMatrix","");
                xmlSetting.setValue("translationVector","");
                xmlSetting.setValue("essentialMatrix","");
                xmlSetting.setValue("fundamentalMatrix","");
            xmlSetting.popTag(); //cameraPair
        }

    xmlSetting.popTag(); //setting

    xmlSetting.saveFile(fileName);
}

void amSetting::createCamera(int id, int index, int captureWidth, int captureHeight, CvMat cameraMatrix, CvMat distCoeffs) {
    amCamera* cam = new amCamera();
    cam->id = id;
    cam->index = index;
    cam->captureWidth = captureWidth;
    cam->captureHeight = captureHeight;
    cam->cameraMatrix = cameraMatrix;
    cam->distCoeffs = distCoeffs;

    cameras.push_back(cam);
}

amCamera* amSetting::getCameraById(int id) {
    amCamera* cam;
    for (unsigned int i = 0 ; i < cameras.size() ; i++) {
        cam = cameras[i];
        if (cam->id == id)
            return cam;
    }
    return NULL;
}

void amSetting::createCameraPair(int id, int cameraId0, int cameraId1, CvMat rotationMatrix, CvMat translationVector, CvMat essentialMatrix, CvMat fundamentalMatrix) {
    amCameraPair* pair = new amCameraPair();
    pair->id = id;
    pair->rotationMatrix = rotationMatrix;
    pair->translationVector = translationVector;
    pair->essentialMatrix = essentialMatrix;
    pair->fundamentalMatrix = fundamentalMatrix;
    pair->setCameras(getCameraById(cameraId0),getCameraById(cameraId1));

    cameraPairs.push_back(pair);
}

amCameraPair* amSetting::getCameraPairById(int id) {
    amCameraPair* camPair;
    for (unsigned int i = 0 ; i < cameraPairs.size() ; i++) {
        camPair = cameraPairs[i];
        if (camPair->id == id)
            return camPair;
    }
    return NULL;
}

void amSetting::saveSetting() {
    xmlSetting.pushTag("setting");

        xmlSetting.setValue("framerate", frameRate);
        xmlSetting.setValue("windowX", windowX);
        xmlSetting.setValue("windowY", windowY);
        xmlSetting.setValue("windowWidth", windowWidth);
        xmlSetting.setValue("windowHeight", windowHeight);

        /* camera */
        amCamera* amCam;
        for (int cam = 0 ; cam < cameras.size() ; cam++) {
            amCam = cameras[cam];
            xmlSetting.pushTag("camera",cam);
                xmlSetting.setValue("id",amCam->id);
                xmlSetting.setValue("index",amCam->index);
                xmlSetting.setValue("captureWidth",amCam->captureWidth);
                xmlSetting.setValue("captureHeight",amCam->captureHeight);
                xmlSetting.setValue("cameraMatrix",amUtil::cvMatToString(&amCam->cameraMatrix,CV_64F));
                xmlSetting.setValue("distCoeffs",amUtil::cvMatToString(&amCam->distCoeffs,CV_64F));
            xmlSetting.popTag(); //camera
        }

        /* cameraPair */
        amCameraPair* amCamPair;
        for (int sp = 0 ; sp < cameraPairs.size() ; sp++) {
            amCamPair = cameraPairs[sp];
            xmlSetting.pushTag("cameraPair",sp);
                xmlSetting.setValue("id",amCamPair->id);
                xmlSetting.setValue("cameraId0",amCamPair->cameraId0);
                xmlSetting.setValue("cameraId1",amCamPair->cameraId1);
                xmlSetting.setValue("rotationMatrix",amUtil::cvMatToString(&amCamPair->rotationMatrix,CV_64F));
                xmlSetting.setValue("translationVector",amUtil::cvMatToString(&amCamPair->translationVector,CV_64F));
                xmlSetting.setValue("essentialMatrix",amUtil::cvMatToString(&amCamPair->essentialMatrix,CV_64F));
                xmlSetting.setValue("fundamentalMatrix",amUtil::cvMatToString(&amCamPair->fundamentalMatrix,CV_64F));
            xmlSetting.popTag(); //cameraPair
        }
        amCamPair = cameraPairs[0];
        //printf("%f %f %f %f %f %f %f %f %f \n",amCamPair->getCamera0()->cameraMatrix.data.db[0],amCamPair->getCamera0()->cameraMatrix.data.db[1],amCamPair->getCamera0()->cameraMatrix.data.db[2],amCamPair->getCamera0()->cameraMatrix.data.db[3],amCamPair->getCamera0()->cameraMatrix.data.db[4],amCamPair->getCamera0()->cameraMatrix.data.db[5],amCamPair->getCamera0()->cameraMatrix.data.db[6],amCamPair->getCamera0()->cameraMatrix.data.db[7],amCamPair->getCamera0()->cameraMatrix.data.db[8],amCamPair->getCamera0()->cameraMatrix.data.db[9]);
        //printf(cvMatToString(&amCamPair->rotationMatrix).c_str());

    xmlSetting.popTag(); //setting

    xmlSetting.saveFile(fileName);
}

void amSetting::setupWindow() {
    ofSetFrameRate(frameRate);
    ofSetWindowPosition(windowX, windowY);
    ofSetWindowShape(windowWidth, windowHeight);
}
