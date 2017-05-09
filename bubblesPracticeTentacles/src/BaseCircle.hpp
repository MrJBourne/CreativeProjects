//
//  BaseCircle.hpp
//  bubblePractice
//
//  Created by D l Samual on 29/03/2017.
//
//

#ifndef BaseCircle_hpp
#define BaseCircle_hpp

#include "Bubbles.hpp"
#include <stdio.h>
#include "ofMain.h"



class BaseCircle{
protected:
    
private:
    
public:
    
    //friend class Bubbles;
    
    int waveHeight;
    int waveAmount;
    int circleResolution = 800;
    float radius = 200;
    float pointY = 0;
    float radiusAddon;
    float sinePercentage;
    float x, y;
    float angle;
    float random;
    
    //bool distance = false;

    float HALF_WIDTH = ofGetWidth()/2;
    float HALF_HEIGHT = ofGetHeight()/2;
    
    vector <ofColor> colours;
    float colourNo = 0;

    ofColor colour;
    ofColor colDist;
    ofColor globalColour;
    ofColor waveColour;
    
    void setup();
    void distanceEffect();
    void effect();
    void sound();
    void update();
    void draw();
    
    BaseCircle();
    
    ofPolyline circle;
    ofPolyline newCircle;
    ofPolyline newCirclePlus;
    
};
#endif /* BaseCircle_hpp */
