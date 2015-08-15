#include "ofApp.h"

#define width 640
#define height 480

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing() ;
    ofEnableAlphaBlending();
    
    //加算合成
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    //ビデオサイズの決定
    camWidth=width;
    camHeight=height;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    //画像処理後の領域の設定
    camImage.allocate(camWidth,camHeight,OF_IMAGE_COLOR);
    
    convertImage.allocate(camWidth, camHeight, OF_IMAGE_GRAYSCALE);
    
    //convertの数を決定
    convertNo[0]=0;
    convertNo[1]=0.5;   ///////////////
    convertNo[2]=0;     ///////////////
    convertNo[3]=0.5;   ///0./0.5/0.///
    convertNo[4]=0;     ///0.5/0/0.5///
    convertNo[5]=0.5;   ///0./0.5/0.///
    convertNo[6]=0;     ///////////////
    convertNo[7]=0.5;   ///////////////
    convertNo[8]=0;
    
    convertImagePixels = convertImage.getPixels();
    
    for (int i=0; i<camWidth; i++) {
        for (int j=0; j<camHeight; j++) {
            frameStock[j*camWidth+i][0]=0;
            frameStock[j*camWidth+i][1]=0;
            convertStock[j*camWidth+i]=0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //カメラからキャプチャする
    vidGrabber.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    //vidGrabber.draw(0,0);
    
    //ムービーのビットマップの解析　配列への代入
    unsigned char * pixels =vidGrabber.getPixels();
    
    //unsigned char * imagePixels =camImage.getPixels();
    
    
   /* for (int i=0; i<camWidth; i++) {
        for (int j=0; j<camHeight; j++) {
            imagePixels[(j*camWidth+i)*3]=pixels[(j*camWidth+i)*3];
            imagePixels[(j*camWidth+i)*3+1]=pixels[(j*camWidth+i)*3+1];
            imagePixels[(j*camWidth+i)*3+2]=pixels[(j*camWidth+i)*3+2];
        }
    } */
    //前の演算結果を引く
    for (int i=0; i<camWidth; i++) {
        for (int j=0; j<camHeight; j++) {
            //
            if(convertImagePixels[j*camWidth+i] - frameStock[j*camWidth+i][1] >= 0){
                convertImagePixels[j*camWidth+i] -= frameStock[j*camWidth+i][1];
            }else{
                convertImagePixels[j*camWidth+i]=0;
            }
        }
    }
    
    //叩き込み処理
    for (int x=0; x<camWidth; x++) {
        
        for (int y=0; y<camHeight; y++) {
            
            float mathNo = 0;
            
            if(y-1 >= 0 ){
                //mathNo += convertImagePixels[(y-1)*camWidth+(x-1)]*convertNo[0];
                mathNo += convertImagePixels[(y-1)*camWidth+x]*convertNo[1];
                //mathNo += convertImagePixels[(y-1)*camWidth+(x+1)]*convertNo[2];
            }
            
            if(x-1 >= 0 && x+1 < camWidth){
                mathNo += convertImagePixels[y*camWidth+(x-1)]*convertNo[3];
                //mathNo += convertImagePixels[y*camWidth+x]*convertNo[4];
                mathNo += convertImagePixels[y*camWidth+(x+1)]*convertNo[5];
            }
            
            if(y+1 < camHeight){
                //mathNo += convertImagePixels[(y+1)*camWidth+(x-1)]*convertNo[6];
                mathNo += convertImagePixels[(y+1)*camWidth+x]*convertNo[7];
                //mathNo += convertImagePixels[(y+1)*camWidth+(x+1)]*convertNo[8];
            }
            
            
//            if(mathNo > 254){
//                mathNo=254;
//            }
//            
//            if(mathNo < 0){
//                mathNo = 0;
//            }
            
            frameStock[y*camWidth+x][1] = frameStock[y*camWidth+x][0];
            frameStock[y*camWidth+x][0] = convertStock[y*camWidth+x];
            convertStock[y*camWidth+x] = mathNo;
            
        }
        
    }
    
    for (int i=0; i<camWidth; i++) {
        
        for (int j=0; j<camHeight; j++) {
            
            float _stock = 0;
            _stock = (float)convertStock[j*camWidth+i];
            convertImagePixels[j*camWidth+i] = (char)_stock;
            
        }
        
    }
    for (int i=0; i<camWidth; i++) {
        for (int j=0; j<camHeight; j++) {
            convertImagePixels[j*camWidth+i]+=255;
            convertImagePixels[j*camWidth+i]/=2;
            
            if(convertImagePixels[j*camWidth+i] > 255){
                convertImagePixels[j*camWidth+i]=255;
            }else if(convertImagePixels[j*camWidth+i] < 0){
                convertImagePixels[j*camWidth+i]=0;
            }
        }
    }
    
    convertImage.update();
    
    convertImage.draw(0,0);

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
    
    unsigned char * convertImagePixels = convertImage.getPixels();
    
    convertImagePixels[camWidth*y+x]=254;
    
    convertImage.update();
    
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
