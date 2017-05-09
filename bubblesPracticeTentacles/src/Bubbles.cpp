//
//  Bubbles.cpp
//  BubblesThatWorks
//
//  Created by D l Samual on 30/03/2017.
//
//

#include "Bubbles.hpp"

Bubbles:: Bubbles(){
    
}

void Bubbles::setup(float _x, float _y, float _dim){
    
    location.x = _x;
    location.y = _y;
    life = _dim;
    
    gravity.set(0, -0.3);
    velocity.set(0,0);
    acceleration.set(0,-0.002);
    
    colour.r = ofRandom(20, 90);
    colour.g = ofRandom(90, 110);
    colour.b = ofRandom(200, 255);
    colour.a = 40;
}

void Bubbles::moveBubble(){

    sineWave = sin((ofGetFrameNum()/life)*0.5);
    path.set(sineWave, 0);
    
    float dx = ofMap(ofGetMouseX(), 0, ofGetWidth(), -2, 2);
    wind.set(dx, 0);
    
    velocity += acceleration;
    gravity += velocity;
    location += gravity;
    location += wind*(life*0.2);
    location+=path;

    float shrink = 0.1;
    life -= shrink;
    
}

void Bubbles::drawBubble(){
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    ofSetColor(colour);//colour
    ofDrawEllipse(location.x, location.y, life, life);
}

void Bubbles::press(){
    
}


