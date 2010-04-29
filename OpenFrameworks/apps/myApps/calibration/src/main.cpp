#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "amCalibrationApp.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	//ofSetupOpenGL(&window, 768, 768, OF_GAME_MODE);
    ofSetupOpenGL(&window, 768, 768, OF_WINDOW);


    ofRunApp(new amCalibrationApp());
	//ofRunApp( new testApp());
}
