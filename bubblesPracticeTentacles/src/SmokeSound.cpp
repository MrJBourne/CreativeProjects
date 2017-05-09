//
//  SmokeSound.cpp
//  bubblePractice
//
//  Created by D l Samual on 29/04/2017.
//
//

#include "SmokeSound.hpp"

SmokeSound:: SmokeSound(){
    
}

void SmokeSound:: smokeSoundSetup(){
    
    smoke.load("sounds/Car.wav");
    //smoke.setVolume(0.75f);
    smoke.setMultiPlay(false);
    smoke.setLoop(true);
    smoke.play();
    
}

void SmokeSound:: forSmoke(){
    
    smoke.setPaused(false);
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    float soundSpeed = ofMap(distance, 0, 700, 0.1f, 2.0f);
    
    smoke.setSpeed(soundSpeed);
    
}

void SmokeSound:: smokeSoundClick(){
    
}

void SmokeSound:: smokeSoundStop(){
    
}

void SmokeSound:: forWaves(){
    
    smoke.setPaused(false);
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    float soundSpeed = ofMap(distance, 0, 700, 1.0f, 0.1f);
    
    smoke.setSpeed(soundSpeed);
    
}
