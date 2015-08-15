#include "ofMain.h"
#include "ofApp.h"
#define width 640
#define height 480

//========================================================================
int main( ){
	ofSetupOpenGL(width,height,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
