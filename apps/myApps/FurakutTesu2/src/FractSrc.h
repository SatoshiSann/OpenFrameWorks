#pragma once

#include "ofMain.h"
#include <math.h>

class FRACT {
public:
    ofColor color,bcolor;
    int generation; //世代
    
    void Saiki(int n, vector <ofPoint *> p1 ,int* length,float* lengthRatio,int ChildNo);
};
