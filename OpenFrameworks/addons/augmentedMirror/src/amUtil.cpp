#include "amUtil.h"

CvMat amUtil::stringToCvMat(string* str, int row, int col, int type) {
    void* Mat;
    if (type == CV_64F) {
        double* M = new double[row*col];
        vector<string> Ms;
        pystring::split(*str, Ms," ");

        if (Ms.size() >= row*col) { //check if the string has enought elements
            for (int i = 0 ; i < row*col ; i++) {
                M[i] = atof(Ms[i].c_str());
            }
        } else {
            for (int i = 0 ; i < row*col ; i++) {
                M[i] = 0;
            }
        }
        Mat = M;
    } else if (type == CV_32F) {
        float* M = new float[row*col];
        vector<string> Ms;
        pystring::split(*str, Ms," ");

        if (Ms.size() >= row*col) { //check if the string has enought elements
            for (int i = 0 ; i < row*col ; i++) {
                M[i] = atof(Ms[i].c_str());
            }
        } else {
            for (int i = 0 ; i < row*col ; i++) {
                M[i] = 0;
            }
        }
        Mat = M;
    } else {
        ofLog(OF_LOG_FATAL_ERROR,"stringToCvMat does not support that type.");
    }


    return cvMat(row,col,type,Mat);
}

string amUtil::cvMatToString(CvMat* mat, int type) {
    vector<string> vec;
    string str;
    if (type == CV_64F){
        double* ary = mat->data.db;
        for (int i = 0 ; i < mat->rows*mat->cols ; i++) {
            vec.push_back(ofToString(ary[i]));
        }
    } else if (type == CV_32F){
        float* ary = mat->data.fl;
        for (int i = 0 ; i < mat->rows*mat->cols ; i++) {
            vec.push_back(ofToString(ary[i]));
        }
    } else {
        ofLog(OF_LOG_FATAL_ERROR,ofToString(type));
    }

    str = pystring::join(" ",vec);
    return str;
}

ofxVec3f amUtil::diaparityToDepth(ofxVec3f* in, CvMat* disparityToDepthMatrix) {
    ofxVec3f out;
    double q[4][4];
    CvMat Q = cvMat(4, 4, CV_64F, q);
    cvConvert( disparityToDepthMatrix, &Q );

    double x = in->x;
    double y = in->y;
    double d = in->z;

    double qx = q[0][1]*y + q[0][3], qy = q[1][1]*y + q[1][3];
    double qz = q[2][1]*y + q[2][3], qw = q[3][1]*y + q[3][3];

    qx += q[0][0]*x;
    qy += q[1][0]*x;
    qz += q[2][0]*x;
    qw += q[3][0]*x;

    double iW = 1./(qw + q[3][2]*d);
    out.x = (qx + q[0][2]*d)*iW;
    out.y = (qy + q[1][2]*d)*iW;
    out.z = (qz + q[2][2]*d)*iW;

    return out;
}
