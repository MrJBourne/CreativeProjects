//
//  Bubbles.hpp
//  BubblesThatWorks
//
//  Created by D l Samual on 30/03/2017.
//
//

#ifndef Bubbles_hpp
#define Bubbles_hpp

#include <stdio.h>
#include <ofMain.h>
//#include <ofApp.h>

class Bubbles{
private:
    
    public:

    void setup(float _x, float _y, float _dim);
    void drawBubble();      //draw the bubbles
    void moveBubble();      //move the bubble
    //void update();      //update the bubble
    void press();
    
    int mass;
    float life;
    float amount;
    float sineWave;
    ofColor colDist;
    
    bool dead = false;
    
    ofColor colour;
    
    Bubbles();
        
    ofVec2f acceleration;
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f gravity;
    ofVec2f wind;
    ofVec2f path;
    
};

#endif /* Bubbles_hpp */
