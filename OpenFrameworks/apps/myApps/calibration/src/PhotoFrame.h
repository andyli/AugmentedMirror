#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#include "ofxMSAInteractiveObject.h"

class PhotoFrame : public ofxMSAInteractiveObject {
    public:
        static PhotoFrame* overFrame;

        int fileNum;
        bool isPhotoTaken;

        ofColor color;
        ofColor colorMouseOver;
        ofColor colorPhotoTaken;

    private:
        void setup();


        void exit() {}


        void update() {}


        void draw();

        virtual void onRollOver(int x, int y);

/*
        virtual void onRollOut() {
            PhotoFrame::overFrame = NULL;
        }


	virtual void onMouseMove(int x, int y){
		printf("MyTestObject::onMouseMove(x: %i, y: %i)\n", x, y);
	}

	virtual void onDragOver(int x, int y, int button) {
		printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void onDragOutside(int x, int y, int button) {
		printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void onPress(int x, int y, int button) {
		printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void onRelease(int x, int y, int button) {
		printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void onReleaseOutside(int x, int y, int button) {
		printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void keyPressed(int key) {
		printf("MyTestObject::keyPressed(key: %i)\n", key);
	}

	virtual void keyReleased(int key) {
		printf("MyTestObject::keyReleased(key: %i)\n", key);
	}
*/
};

#endif // PHOTOFRAME_H
