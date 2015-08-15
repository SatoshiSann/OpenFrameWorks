#include "FractSrc.h"

void FRACT::Saiki(int n ,vector <ofPoint *> p1 ,int* length ,float* lengthRatio ,int childNo){
    ofPoint p3,p4,p5,ZEROPOINT;
    ZEROPOINT = ofPoint(0,0);
    
    if(n > 0){
        
        if(generation != n){
            for(int i=0;i<p1.size();i++){
                p1[i]->x = p1[i]->x * lengthRatio[childNo];
            }
        }
        
        ofPushMatrix();
        
        ofPoint LineP1,LineP2;
        for(int i=0;i<p1.size()-1;i++){
            LineP1 = ofPoint(p1[i]->x,p1[i]->y);
            LineP2 = ofPoint(p1[i+1]->x,p1[i+1]->y);
            ofLine(LineP1,LineP2);
        }
        
        for(int i=0;i<p1.size();i++){
            Saiki(n-1,p1,length,lengthRatio,i);
        }
        

        
        ofPopMatrix();
        
    }
}