#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#define convert 9
#define width 640
#define height 480

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    
    ofImage camImage;
    ofImage convertImage;
    
    char CONVERT_ROW = 3;
    char CONVERT_COL = 3;
    char CONVERT_NUM = CONVERT_ROW*CONVERT_COL;
    float convertNo[convert];
    
    unsigned char * convertImagePixels;
    unsigned char frameStock[width*height][2];
    unsigned char convertStock[width*height];
};
