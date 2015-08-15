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
		
    
        static const int HAIRETU=3;
        float aTanZ[HAIRETU];
        float aTanX[HAIRETU];
    
        FRACT myFra;
    
        ofPoint pos1[HAIRETU];
        ofPoint pos2[HAIRETU];
        int length[HAIRETU];
        float lengthRatio[HAIRETU];
    
    
        ofColor BACK_GROUND_COLOR;
    
};
