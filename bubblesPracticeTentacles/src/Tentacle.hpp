//
//  Tentacle.hpp
//  bubblePractice
//
//  Created by D l Samual on 28/04/2017.
//
//

#ifndef Tentacle_hpp
#define Tentacle_hpp

#include <stdio.h>
#include <ofMain.h>
#include "Waves.hpp"

//class Tentacle{
class Tentacle: public Waves{
    
private:
    
public:
    
    void setup(float _x, float _y);
    void positionSegment(float a, float b);
    void positionSegments();
    void reachSegment(float i, float xin, float yin);
    void reachSegments(int inx, int iny);
    void segment(float x, float y, float a, float sw);
    void draw();
    
    void newLoc(float _x, float _y);
    void reposition();
    
    float numSegments = 20;//25;
    float segLength = 15;
    float targetX, targetY;
    
    float HALF_WIDTH = ofGetWidth()/2;
    float HALF_HEIGHT = ofGetHeight()/2;
    
    vector <float> x;
    vector <float> y;
    vector <float> angle;
    
    float colour;
    
    Tentacle();
    
};

#endif /* Tentacle_hpp */
