//
//  Waves.cpp
//  bubblePractice
//
//  Created by D l Samual on 29/03/2017.
//
//

#include "Waves.hpp"

Waves::Waves(){
    
}

void Waves:: update(){
        clr.set(10,100,240, 50);
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    colDist = ofMap(distance, ofGetWindowWidth()*0.8, 0, 0, 255);
    newCircle = circle;
    newCirclePlus = circle;
    
    waveHeight = radius*0.1;//height of the sine wave
    waveAmount = 5;//amount of sine waves per circle
    
    for(int i = 0; i < circleResolution; i++){
        
        angle = TWO_PI/circleResolution*i;
        
        radiusAddon = waveHeight*sin((angle+speedIncrement)*waveAmount);//multpily angle by amount of waves
        radiusAddon2 = waveHeight*sin((angle-speedIncrement)*waveAmount);
        
        float radiusAddon3 = waveHeight*sin((angle+speedIncrement*0.9)*waveAmount);
        
        ofVec2f p2(circle[i].x, circle[i].y);
        ofVec2f p1(ofGetMouseX()-ofGetWidth()/2, ofGetMouseY()-ofGetHeight()/2); //not sure why, need to take away half the W and H
        float bias = p1.distance(p2);
        
        float pointX2 = cos(angle)*(radius+radiusAddon2);
        float pointY2 = sin(angle)*(radius+radiusAddon2);
        float pointx2 = cos(angle)*(radius+radiusAddon3);
        float pointy2 = sin(angle)*(radius+radiusAddon3);
        
        if(bias<250){ //if the mouse is close enough, create pattern
            
            pointX = cos(angle)*(radius+radiusAddon);// /10 || * 0.1
            pointY = sin(angle)*(radius+radiusAddon);// /10 || * 0.1
            
            circle[i].x = pointX;
            circle[i].y = pointY;
                        
            newCircle[i].x = pointX2*1.1;
            newCircle[i].y = pointY2*1.1;
            
            newCirclePlus[i].x = pointx2*0.9;
            newCirclePlus[i].y = pointy2*0.9;
            }
        }
}

void Waves:: draw(){
    
    speedIncrement = ofGetElapsedTimef();//    /2
    
    //ofColor blue;
    ofColor black;
    
    mapX = ofMap(Bias, 0, 100, 0, 255, true);
    
    colour.r = 5;
    colour.g = 10;
    colour.b = 30;
    
    black = 0;
    
    //turning the distance into a colour value
    //ofColor
    ofSetLineWidth(7);//7
    ofSetColor(waveColour);//colour
    circle.close();
    circle = circle.getSmoothed(10);
    circle.draw();
    
    newCircle.close();
    ofSetLineWidth(10);
    newCircle = newCircle.getSmoothed(10);
    newCircle.draw();
    
    newCirclePlus.close();
}

