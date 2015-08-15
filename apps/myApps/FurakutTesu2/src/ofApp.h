#pragma once

#include "ofMain.h"
#include "FractSrc.h"

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
		
    
        static const int TT=0;
        FRACT myFra;
        FRACT myFra2;
        vector <ofPoint *> pos1;
        int * length;
        float * lengthRatio;
        ofColor BACK_GROUND_COLOR;
};
