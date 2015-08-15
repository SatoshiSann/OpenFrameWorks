#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing() ;
    ofEnableAlphaBlending();
    
    //加算合成
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    //ビデオサイズの決定
    camWidth=480;
    camHeight=320;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    //カメラからキャプチャする
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    vidGrabber.draw(20, 20);
    //ムービーのビットマップの解析　配列への代入
    unsigned char * pixels =vidGrabber.getPixels();
    //画像を10pxごとスキャン
    for (int i=0; i<camWidth; i+=10) {
        for (int j=0; j<camHeight; j+=10) {
            //RGBそれぞれを取得
            unsigned char r=pixels[(j*camWidth+i)*3];
            unsigned char g=pixels[(j*camWidth+i)*3+1];
            unsigned char b=pixels[(j*camWidth+i)*3+2];
            
            //取得した値をもとに描画
            //強さに比例して園を大きくする
            ofSetColor(255, 0, 0,100);
            ofCircle(camWidth+40 + i, 20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0,100);
            ofCircle(camWidth+40 + i, 20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255,100);
            ofCircle(camWidth+40 + i, 20+j,20.0*(float)b/255.0);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' || key == 'S'){
        vidGrabber.videoSettings();
    }
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
