#pragma once

#include "ofMain.h"
#include <math.h>

class FRACT {
    
public:
    ofColor color,bcolor;
    int generation; //世代
    int HAIRETU;
    float* lengthRatio;
    float* KakudoZ;
    float* KakudoX;
    ofPoint* posRes;
    
    
    FRACT(int _HAIRETU,float* _lengthRatio,float* _KakudoX,float* _KakudoZ,ofPoint* _posRes);
    void Saiki(int n,ofPoint* p1 ,int ChildNo);
};
