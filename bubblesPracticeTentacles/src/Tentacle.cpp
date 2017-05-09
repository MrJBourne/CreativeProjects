//
//  Tentacle.cpp
//  bubblePractice
//
//  Created by D l Samual on 28/04/2017.
//
//

#include "Tentacle.hpp"
#include "Horror.hpp"

Tentacle:: Tentacle(){
    
}

void Tentacle:: setup(float _x, float _y){
    
    for(int i = 0; i < numSegments; i++){
        
        x.push_back(_x);
        y.push_back(_y);
        angle.push_back(0);
    }
}

void Tentacle:: reposition(){
   
    //for(int i = 0; i < 10; i++){
        x[0] +=2;//circle[i*80].x;
        y[0] +=2;// circle[i*80].y;
   // }
}

void Tentacle:: newLoc(float _x, float _y){
    
    for(int i = 0; i < numSegments; i++){
        x[i] = _x;
        y[i] = _y;
    }
}

void Tentacle:: positionSegment(float a, float b){
    
    x[b] = x[a] + cos(angle[a]) * segLength;
    y[b] = y[a] + sin(angle[a]) * segLength;
    
}

void Tentacle::positionSegments(){
    
    for(int j = x.size()-1; j>=1; j--) {
        positionSegment(j, j-1);
    }
}

void Tentacle:: reachSegment(float i, float xin, float yin){
    
    float dx = xin - x[i];
    float dy = yin - y[i];
    
    angle[i] = atan2(dy ,dx);
    targetX = xin - cos(angle[i]) * segLength;
    targetY = yin - sin(angle[i]) * segLength;
    
}

void Tentacle::reachSegments(int inx, int iny)
{
    reachSegment(0, inx, iny);
    
    for(int i=0; i<numSegments; i++)
    {
        reachSegment(i, targetX, targetY);
    }
}

void Tentacle::segment(float x, float y, float a, float sw){

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotate(ofDegToRad(a));
    ofSetColor(0);
    ofDrawEllipse(0, 0, sw, sw);
    ofPopMatrix();
    ofPopStyle();
    
}

void Tentacle:: draw(){
    
    for(int i = 0; i < numSegments; i++){
        
        segment(x[i], y[i], angle[i], 1 + i * 2);
        ofSetColor(0);
        ofDrawCircle(0, 0, 0,0);
    }
}
