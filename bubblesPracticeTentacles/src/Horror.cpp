//
//  Horror.cpp
//  bubblePractice
//
//  Created by D l Samual on 15/04/2017.
//
//
//  INACTIVE
#include "Horror.hpp"

Horror::Horror(){
    
}

void Horror:: draw(){
    
    //Same as Waves class except colour is black
    speedIncrement = ofGetElapsedTimef()/2;//    /2
    
    ofColor black;
    
    black = 0;
    //ofSetLineWidth(7);//7;
    ofSetColor(black);
    circle.close();
    circle = circle.getSmoothed(10);
    circle.draw();
    
    newCircle.close();
    ofSetLineWidth(10);
    newCircle = newCircle.getSmoothed(10);
    ofSetLineWidth(10);
    newCircle.draw();
    
    newCirclePlus.close();
    ofSetLineWidth(5);
}

