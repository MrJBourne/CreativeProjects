//
//  Smoke.hpp
//  bubblePractice
//
//  Created by D l Samual on 11/04/2017.
//
//

#ifndef Smoke_hpp
#define Smoke_hpp

#include <stdio.h>
#include <ofMain.h>

class Smoke{
    
private:
    
public:
    
    void setup(float _x, float _y, float _dim);
    void drawBubble();      //draw the bubbles
    void moveBubble();      //move the bubble
    //void update();      //update the bubble
    
    int mass;
    float life;
    float amount;
    float dy;
    bool dead = false;
    float random;
    float minus;
    float shrink;
    
    ofColor colour;
    ofColor colDist;
    
    Smoke();
    
    ofVec2f acceleration;
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f gravity;
    ofVec2f wind;
    
};

#endif /* Smoke_hpp */
