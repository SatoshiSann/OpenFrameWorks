#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    BACK_GROUND_COLOR = ofColor(0,0,0);
    ofEnableAlphaBlending();
    ofBackground(BACK_GROUND_COLOR);
    ofSetFrameRate(3);
    ofSetColor(0,255,0);
    
    
    int LINEPOINT;
    LINEPOINT=10;
    
    pos1.push_back(new ofPoint(0,ofGetHeight()*2/4,0));
    
    for(int i=1;i<LINEPOINT-1;i++){
        pos1.push_back(new ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(100)));
    }
    
    pos1.push_back(new ofPoint(0,ofGetHeight()*2/4,0));
    
    
    for(int i=0;i<pos1.size()-1;i++){
        length=new int(sqrt (pow(pos1[i+1]->x - pos1[i]->x,2) + pow(pos1[i+1]->y - pos1[i]->y,2) + pow(pos1[i+1]->z - pos1[i]->z,2) ));
    }
    
    length =new int(sqrt( pow(pos1[LINEPOINT]->x - pos1[0]->x,2) + pow(pos1[LINEPOINT]->y - pos1[0]->y,2) + pow(pos1[LINEPOINT]->z - pos1[0]->z,2) ));
    
    
    for(int i=0;i<pos1.size();i++){
        lengthRatio=new float(length[i]/length[LINEPOINT]);
    }
    
    myFra.generation = 2;
    myFra.bcolor = BACK_GROUND_COLOR;
    myFra.color = ofColor(0,255,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    myFra.Saiki(myFra.generation, pos1, length,lengthRatio,0);
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
