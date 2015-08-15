#include "FractSrc.h"

void FRACT::Saiki(int n,ofPoint p1,ofPoint p2,int _fusi){
    ofPoint p3,p4,p5,ZEROPOINT;
    ZEROPOINT = ofPoint(0,0);
    int fusi;
    fusi=_fusi;
    if(n > 0){
        
        switch (n) {
            case 1:
                ofSetColor(255,0,0);
                break;
                
            case 2:
                ofSetColor(0,255,0);
                break;
                
            case 3:
                ofSetColor(0,0,255);
                break;
                
            case 4:
                ofSetColor(255,255,0);
                break;
                
            case 5:
                ofSetColor(0,255,255);
                break;
                
                
            default:
                ofSetColor(255,255,255);
                break;
        }
        
        p3 = ofPoint((p2.x-p1.x)/fusi,0);
        p4 = ofPoint((p2.x-p1.x)/fusi,p2.y);
        
        ofPushMatrix();
        
        ofTranslate(p1);
        ofLine(ZEROPOINT,p3);
        Saiki(n-1,ZEROPOINT,p4,fusi);
        
        ofTranslate(p3);
        
        ofRotateZ(60);
        ofLine(ZEROPOINT,p3);
        Saiki(n-1,ZEROPOINT,p4,fusi);
        
        ofTranslate(p3);
        ofRotateZ(-60);
        
        ofRotateZ(-60);
        ofLine(ZEROPOINT,p3);
        Saiki(n-1,ZEROPOINT,p4,fusi);
        
        
        ofTranslate(p3);
        ofRotateZ(60);
        
        ofLine(ZEROPOINT,p3);
        Saiki(n-1,ZEROPOINT,p4,fusi);
        
        ofPopMatrix();
        //ofLine(p1,p2);
        
    }
}

/*
cos(radian(PI*2=360度))*p3.x;
*/