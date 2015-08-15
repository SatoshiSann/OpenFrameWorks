#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    BACK_GROUND_COLOR = ofColor(0,0,0); //背景色の設定(RGB)
    ofEnableAlphaBlending(); //Alphaチャンネルの許可
    ofBackground(BACK_GROUND_COLOR); //バックグラウンドを背景色に設定
    ofSetFrameRate(1); //フレームレートの設定
    ofSetColor(0,255,0); //線の色の設定(RGB)
    
    pos1[0]=ofPoint(ofGetWidth()/2-100,ofGetHeight()/2,0); //線の最初のポイントの設定
    
    //各ポイントの設定ofPoint(x,y,z)
    for(int i=1;i<HAIRETU-1;i++){
        //pos1[i]=ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(100));
        pos1[i]=ofPoint(ofGetWidth()/2,ofGetHeight()/4+100,0);
    }
    
    pos1[HAIRETU-1]=ofPoint(ofGetWidth()/2+100,ofGetHeight()/2,0); //線の最後のポイントの設定
    
    
    //初期ポイントをpos2にも入れる
    for(int i=0;i<HAIRETU;i++){
        pos2[i]=pos1[i];
    }
    
    //各辺の長さの算出
    for(int i=0;i<HAIRETU-1;i++){
        length[i]=sqrt (pow(pos1[i+1].x - pos1[i].x,2) + pow(pos1[i+1].y - pos1[i].y,2) + pow(pos1[i+1].z - pos1[i].z,2) );
    }
    
    //最初の点と最後の点の長さを取得　長さ配列の一番最後に入れる
    length[HAIRETU-1] =sqrt( pow(pos1[HAIRETU-1].x - pos1[0].x,2) + pow(pos1[HAIRETU-1].y - pos1[0].y,2) + pow(pos1[HAIRETU-1].z - pos1[0].z,2) );
    
    
    //最初と最後の点の長さと各辺の長さの比を算出
    for(int i=0;i<HAIRETU;i++){
        lengthRatio[i]=length[i]/length[HAIRETU-1];
    }
    
    //各辺の角度を算出(360度)
    for(int i=0;i<HAIRETU-1;i++){
        aTanZ[i] = atan2(pos1[i+1].x-pos1[i].x,pos1[i+1].y-pos1[i].y) * 180 / PI;
        aTanX[i] = atan2(pos1[i+1].z-pos1[i].z,pos1[i+1].y-pos1[i].y) * 180 / PI;

    }
    
    
    myFra = *new FRACT(HAIRETU,lengthRatio,aTanX,aTanZ,pos2); //フラクタルクラスの作成
    
    myFra.generation = 3; //何世代まで描画するかの設定
    myFra.bcolor = BACK_GROUND_COLOR; //バックグラウンドカラーの受け渡し
    myFra.color = ofColor(0,255,0); //描画色の設定
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //pos1の初期化
    for(int i=0;i<HAIRETU;i++){
        pos1[i]=pos2[i];
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //フラクタルの描画()
    myFra.Saiki(myFra.generation, pos1 ,0);
    
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
