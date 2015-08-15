#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    BACK_GROUND_COLOR = ofColor(0,0,0);
    ofEnableAlphaBlending();
    ofBackground(BACK_GROUND_COLOR);
    ofSetFrameRate(3);
    pos1 = ofPoint(ofGetWidth()/4,ofGetHeight()*2/4);
    pos2 = ofPoint(ofGetWidth()-ofGetWidth()/4,ofGetHeight()*2/4);
    myFra.generation = 2;
    myFra.bcolor = BACK_GROUND_COLOR;
    myFra.color = ofColor(0,255,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    myFra.Saiki(myFra.generation, pos1, pos2 , 3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
