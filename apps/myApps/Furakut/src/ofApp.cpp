#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    BACK_GROUND_COLOR = ofColor(0,0,0);
    ofBackground(BACK_GROUND_COLOR);
    ofSetFrameRate(30);
    pos1 = ofPoint(100, 100, 0);
    pos2 = ofPoint(ofGetWidth()*2/4, ofGetHeight()/2, -400);
    pos3 = ofPoint(ofGetWidth()*3/4, ofGetHeight()/3, -200);
    pos4 = ofPoint(100, 100, -100);
    
    
    myFra.generation = 4;
    myFra.bcolor = BACK_GROUND_COLOR;
    myFra.color = ofColor(0,255,0);
    
    rotateX = 0;
    rotateZ = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    myFra.frameCount++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(myFra.frameCount >300){
        rotateX++;
        rotateZ++;
    }
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateX(rotateX % 360);
    ofRotateY(rotateZ % 360);
    ofTranslate(-ofGetWidth()/2,-ofGetHeight()/2);

    myFra.Saiki(myFra.generation, pos1, pos2, pos3, pos4);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'w'){
        rotateX+=3;
        rotateX=rotateX % 360;
    }else if(key == 's'){
        rotateX-=3;
        if(rotateX < 0){
            rotateX=360+rotateX;
        }
    }else if(key == 'a'){
        rotateZ+=3;
        rotateX=rotateX % 360;
    }else if(key == 'd'){
        rotateZ-=3;
        if(rotateZ < 0){
        rotateZ=360+rotateZ;
        }
    }
    myFra.frameCount = 0;
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
