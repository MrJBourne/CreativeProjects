//
//  Buttons.hpp
//  bubblePractice
//
//  Created by D l Samual on 03/05/2017.
//
//

#ifndef Buttons_hpp
#define Buttons_hpp

#include <stdio.h>
#include <ofMain.h>

class Buttons{
    
public:
    
    void setup();
    void colour();
    void horrorOn();
    void horrorOff();
    void water();
    void smoke();
    void all();
    
    float distance;
    
    ofImage horrorOnButton;
    ofImage waterButton;
    ofImage smokeButton;
    ofImage horrorOffButton;
    ofImage button;
    
    ofColor colDist;
    ofColor waterColour;
    
    Buttons();
};

#endif /* Buttons_hpp */
