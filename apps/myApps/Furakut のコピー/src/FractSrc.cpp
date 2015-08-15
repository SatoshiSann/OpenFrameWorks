#include "FractSrc.h"
#define xRadi 2
#define zRadi 2

void FRACT::Saiki(int n,ofPoint p1,ofPoint p2,ofPoint p6 ,ofPoint p7){
    ofPoint p3,p4,p5,p8,p9,p10;
    float WIDTH_HARF = ofGetWidth()/2;
    float HEIGHT_HARF = ofGetHeight()/2;
    
    if(n > 0){
        p3 = (2 * p1 + p2) / 3.0; //内分点 n:mの比で内分点を三次元でとる場合点a・点bとすると　(na+mb/(m+n))
        p4 = (2 * p2 + p1) / 3.0; //内分点
        
        p5.y = p3.y + (p4.y - p3.y) * cos(PI/xRadi) - (p4.z - p3.z) * sin(PI/xRadi);
        p5.z = p3.z + (p4.y - p3.y) * sin(PI/xRadi) + (p4.z - p3.z) * cos(PI/xRadi);
        
        p5.x = p3.x + (p4.x - p3.x) * cos(PI/zRadi) - (p4.y - p3.y) * sin(PI/zRadi);
        p5.y = p3.y + (p4.x - p3.x) * sin(PI/zRadi) + (p4.y - p3.y) * cos(PI/zRadi);
        
        
        p8 = (2 * p6 + p7) / 3.0; //内分点 n:mの比で内分点を三次元でとる場合点a・点bとすると　(na+mb/(m+n))
        p9 = (2 * p7 + p6) / 3.0; //内分点
        
        p10.y = p8.y + (p9.y - p8.y) * cos(PI/xRadi) - (p9.z - p8.z) * sin(PI/xRadi);
        p10.z = p8.z + (p9.y - p8.y) * sin(PI/xRadi) + (p9.z - p8.z) * cos(PI/xRadi);
        
        p10.x = p8.x + (p9.x - p8.x) * cos(PI/zRadi) - (p9.y - p8.y) * sin(PI/zRadi);
        p10.y = p8.y + (p9.x - p8.x) * sin(PI/zRadi) + (p9.y - p8.y) * cos(PI/zRadi);
        
        
        ofPushMatrix();
    
//        ofTranslate(WIDTH_HARF,HEIGHT_HARF);
//        ofRotateX(frameCount % 360);
//        ofTranslate(-WIDTH_HARF,-HEIGHT_HARF);
        
        ofSetColor(bcolor);
        ofLine(p3,p4);
        ofLine(p8,p9);
        
        ofSetColor(color);
        
        ofLine(p1,p3);
        ofLine(p3,p5);
        ofLine(p5,p4);
        Saiki(n-1,p1,p3,p5,p4);
        
        ofLine(p1,p3);
        ofLine(p3,p5);
        ofLine(p5,p4);
        Saiki(n-1,p3,p5,p4,p6);
        
        ofLine(p1,p3);
        ofLine(p3,p5);
        ofLine(p5,p4);
        Saiki(n-1,p5,p4,p6,p8);
        
        ofLine(p1,p3);
        ofLine(p3,p5);
        ofLine(p5,p4);
        Saiki(n-1,p4,p6,p8,p10);
        
        ofPopMatrix();
    }
}
