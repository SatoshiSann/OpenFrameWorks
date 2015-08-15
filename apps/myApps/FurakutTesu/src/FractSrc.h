#pragma once

#include "ofMain.h"
#include <math.h>

class FRACT {
public:
    ofColor color,bcolor;
    int generation; //世代
    int* Kakudo;
    
    void Saiki(int n, ofPoint p1 ,ofPoint p2,int _fusi);
};
