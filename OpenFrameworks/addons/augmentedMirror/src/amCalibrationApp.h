#ifndef AMCALIBRATIONAPP_H
#define AMCALIBRATIONAPP_H

#include <vector>
#include "ofMain.h"
#include "ofxGuiApp.h"
#include "ofxTimer.h"
#include "ofxOpenCv.h"
#include "ofxMSAShape3D.h"
#include "ofx3DUtils.h"
#include "ofxNetwork.h"
#include "amSetting.h"

class amCalibrationApp : public ofxGuiApp
{
    public:
		void setup();
		void update();
		void draw();

		void setupGui();
		void handleGui(int parameterId, int task, void* data, int length);

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		ofxCamera camera;
		ofxLight light;
		float centerX, centerY, centerZ;

		amSetting* amsetting;

		ofxTimer* captureTimer;
		bool timeReached;
		bool firstCapture;
		int numOfCapture;
		int captureInterval; // in seconds
		CvSize patternSize; //chessboard pattern
		float squareSize; //actual square size
		string capturedMsg;
		int capturedMsgCX;
		int capturedMsgCY;

        //captured images
		vector<ofxCvColorImage> capturedCvImages[2];
		vector<bool> isCaptured[2];

		//images for display
		ofxCvColorImage displayImages[2];

		ofTrueTypeFont bigFont;

		//UI
		ofxGuiMatrix* guiPairMatrix;
		ofxGuiButton* guiEnableRectifyButton;
		ofxGuiMatrix* guiCapturePairMatrix;
		ofxGuiButton* guiCapturePairButton;
		ofxGuiButton* guiCalibratePairButton;
		ofxGuiButton* guiShowDisparityButton;
		ofxGuiButton* guiSaveSettingButton;

		void handleTimer(ofEventArgs &args);
		int getFirstUncheckedId(ofxGuiMatrix* guiMat);
		void calibrateSelectedPair();
		amCameraPair* getSelectedCameraPair() { return amsetting->cameraPairs[guiPairMatrix->mValue]; }
		void renderDisparityMap(amCameraPair* camPair);

		ofxTCPServer TCP;
};

#endif // AMCALIBRATIONAPP_H
