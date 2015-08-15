#pragma once

#include "ofMain.h"
#include <math.h>

class FRACT {
public:
    ofColor color,bcolor;
    int generation; //世代
    int frameCount = 0;
    
    void Saiki(int n, ofPoint p1 ,ofPoint p2 ,ofPoint p6 ,ofPoint p7);
};
