//
//  Waves.hpp
//  bubblePractice
//
//  Created by D l Samual on 29/03/2017.
//
//

#ifndef Waves_hpp
#define Waves_hpp

#include <stdio.h>
#include "BaseCircle.hpp"
#include "Bubbles.hpp"

//class Bubbles;

class Waves: public BaseCircle{
    
    //Bubbles blub;
    
public:
    
    virtual void update();
    virtual void draw();

    float speedIncrement;
    float radiusAddon2;
    float Bias;
    float pointX;
    float mapX;
    float bias;
    float x, y;
    
    ofColor clr;
    
    float bubbleX, bubbleY;
    
    Waves();

};

#endif /* Waves_hpp */
