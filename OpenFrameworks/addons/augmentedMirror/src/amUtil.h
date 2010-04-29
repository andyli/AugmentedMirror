#ifndef AMUTIL_H
#define AMUTIL_H

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxTouch.h"
#include "ofxVectorMath.h"
#include "pystring.h"

class amUtil
{
    public:
        static CvMat stringToCvMat(string* str, int row, int col, int type);
        static string cvMatToString(CvMat* mat, int type);
        static bool blobIsLeftOf(ofxTouchBlob i, ofxTouchBlob j) { return i.center.x<j.center.x; }
        static ofxVec3f diaparityToDepth(ofxVec3f* in, CvMat* disparityToDepthMatrix);
};

#endif // AMCAMERASOURCEGRABBER_H
