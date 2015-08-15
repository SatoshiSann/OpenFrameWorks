#include "FractSrc.h"

FRACT::FRACT(int _HAIRETU,float* _lengthRatio,float* _KakudoX,float* _KakudoZ,ofPoint* _posRes){
    HAIRETU = _HAIRETU; //配列の個数
    lengthRatio = _lengthRatio; //各一辺と全体の長さの比の配列
    KakudoX = _KakudoX; //各X軸の角度の配列
    KakudoZ = _KakudoZ; //各Z軸の角度の配列
    posRes = _posRes; //保存用初期配列
}

void FRACT::Saiki(int n ,ofPoint* p1 ,int pointNo){
    
    if(n == 3){
        ofSetColor(color);
    }else if(n==2){
        ofSetColor(0,255,0);
    }else {
        ofSetColor(0,0,255);
    }
    
    for(int i=0;i<HAIRETU;i++){
        p1[i]=posRes[i];
    }
    
    //もし、n番目の子要素が
    if(n > 0){
        for(int i=0;i<HAIRETU-1;i++){
        //親ではない場合
        if(generation != n){
            //p1[0]を起点とした値に変更
            for(int i=0 ; i<HAIRETU; i++){
                p1[i]=ofPoint(p1[i].x - p1[0].x,p1[i].y - p1[0].y,p1[i].z - p1[0].z);
            }
            
            //各値に長さ比をかけてp1に代入
            for(int i=1;i<HAIRETU;i++){
                
                for(int t=0;t < generation-n;t++){
                    float px = float(p1[i].x) * lengthRatio[t];
                    float py = float(p1[i].y) * lengthRatio[t];
                    float pz = float(p1[i].z) * lengthRatio[t];
                    p1[i] = ofPoint(int(px),int(py),int(pz));
                }
                
            }
            
        }
        
        //線の描画
        ofPoint LineP1,LineP2; //線の描画の為の変数の作成
        
            LineP1 = ofPoint(p1[i].x,p1[i].y);
            LineP2 = ofPoint(p1[i+1].x,p1[i+1].y);
            ofLine(LineP1,LineP2);
            
            //再起呼び出し
            if(n > 1){
                ofSetColor(bcolor);
                ofLine(LineP1,LineP2);
                ofPushMatrix();//現在のポジションの保存
                ofTranslate(p1[i]);//各角を起点(0,0,0)に変更
                ofRotateZ(KakudoZ[i]);//各辺のZ軸方向に角度変更
                ofRotateX(KakudoX[i]);//各辺のX軸方向に角度変更
                Saiki(n-1,p1,i);//子要素番号を一つ減らして再起呼び出し(子要素番号,変形済み配列,何番目の点か)
                ofPopMatrix();//元のポジションにする
            }
                
        }
    }
}