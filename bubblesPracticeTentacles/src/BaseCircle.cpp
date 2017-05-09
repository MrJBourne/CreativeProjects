//
//  BaseCircle.cpp
//  bubblePractice
//
//  Created by D l Samual on 29/03/2017.
//
//

#include "BaseCircle.hpp"

BaseCircle::BaseCircle(){
    
}

void BaseCircle:: setup(){
    
    for(int i = 0; i < circleResolution; i++){
        
        angle = TWO_PI/circleResolution*i;
        x = cos(angle)*radius;
        y = sin(angle)*radius;
        
        circle.addVertex(ofPoint(x, y));//, pointY));
    }
    
    circle.close();
    
    //colours.resize(3);
    //colours[1].set(10, 100, 240, 50);//blue
    //colours[2].set(0, 0, 0);//black
    
    //waveColour = (222,179,78);//(10,100,240);
    //waveColour.set(10,100,240, 50);
}

void BaseCircle:: update(){
    
    newCircle = circle;
    newCirclePlus = circle;
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    float left = ofMap(distance, HALF_WIDTH, 0, 2, 0);
    float right = ofMap(distance, 0, HALF_WIDTH, 0, 2);
    
    random = ofRandom(-1.5*left, 1.5*left);
    float random2 = ofRandom(-1.5*left, 1.5*left);
    
    colDist = ofMap(distance, 700, 0, 200, 25);
    
    //if the mouse is near the center of the screen the circle will move by a random value around -2 , 2
    
    for(int i = 0; i < circleResolution; i++){
     
        newCircle[i].x += random;
        newCircle[i].y += random2;
    }
}

void BaseCircle:: draw(){
    
    ofPushStyle();
    newCircle.close();
    
    //ofSetLineWidth(10);//7
    glLineWidth(6);
    ofSetColor(colDist);
    newCircle.draw();
    ofPopStyle();
    
    
}
