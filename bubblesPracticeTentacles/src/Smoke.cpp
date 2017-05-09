//
//  Smoke.cpp
//  bubblePractice
//
//  Created by D l Samual on 11/04/2017.
//
//

#include "Smoke.hpp"

Smoke:: Smoke(){
    
}

void Smoke::setup(float _x, float _y, float _dim){
    
    location.x = _x;
    location.y = _y;
    life = _dim;
    
    gravity.set(0, ofRandom(0.1, -0.2));
    velocity.set(0,0);
    acceleration.set(0,-0.01);
    
    //random = ofRandom(50, 100);
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    colDist = ofMap(distance, 700, 0, 80, 25); //distance from center creates colour
    
    //colour = (222,179,78);
    colour.r = 255;
    colour.g = 191;//247;
    colour.b = 0;//138;
    colour.a=140;
}

void Smoke::moveBubble(){
    
    float dx = ofMap(ofGetMouseX(), 0, ofGetWidth(), 5, -5);
    dy = ofMap(ofGetMouseY(), 0, ofGetHeight(), 2,-2);
    
    wind.set(dx, dy);
    
    //velocity += acceleration;
    gravity += velocity;
    location += gravity;
    location += wind;
    
    shrink = 0.5;
    life += shrink;

}

void Smoke::drawBubble(){
    ofSetColor(colour);
    colDist -= 0.1;
    colour-=5;
    ofDrawEllipse(location.x, location.y, life, life);
}
