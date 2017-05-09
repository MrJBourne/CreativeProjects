//
//  Buttons.cpp
//  bubblePractice
//
//  Created by D l Samual on 03/05/2017.
//
//

#include "Buttons.hpp"

Buttons:: Buttons(){
    
}

void Buttons:: setup(){
    
    horrorOnButton.load("images/horrorOn1.png");
    horrorOffButton.load("images/horrorOff1.png");
    waterButton.load("images/water1.png");
    smokeButton.load("images/smoke1.png");
    button.load("images/button.png");
    
}

void Buttons:: colour(){

    
    
}

void Buttons:: horrorOn(){
    
    distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()-120, 120);
    colDist = ofMap(distance, 0, 400, 255, 0, true);
    ofSetColor(colDist);
    
    ofDrawEllipse(550, -300, 145, 145);
    horrorOnButton.draw(475, -375, 150, 150);
    
}

void Buttons:: horrorOff(){
    
    distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()-120, 320);
    colDist = ofMap(distance, 0, 400, 255, 0, true);
    ofSetColor(colDist);
    
    ofDrawEllipse(550, -100, 145, 145);
    horrorOffButton.draw(475, -175, 150, 150);
    
}

void Buttons:: water(){
    
    distance = ofDist(ofGetMouseX(), ofGetMouseY(), 120, 120);
    colDist = ofMap(distance, 0, 400, 255, 0, true);
    ofSetColor(colDist);
    
    ofDrawEllipse(-550, -300, 145, 145);
    waterButton.draw(-625, -375, 150, 150);
    
}

void Buttons:: smoke(){
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), 120, 320);
    colDist = ofMap(distance, 0, 400, 255, 0, true);
    ofSetColor(colDist);
    
    ofDrawEllipse(-550, -100, 145, 145);
    smokeButton.draw(-625, -175, 150, 150);
    
}

void Buttons:: all(){
    
    horrorOn();
    horrorOff();
    water();
    smoke();
    
}

