//
//  SmokeSound.hpp
//  bubblePractice
//
//  Created by D l Samual on 29/04/2017.
//
//

#ifndef SmokeSound_hpp
#define SmokeSound_hpp

#include <stdio.h>

#include "ofMain.h"

class SmokeSound{
    
private:
    
public:
    
    void smokeSoundSetup();
    void smokeSoundClick();
    void smokeSoundStop();
    void forSmoke();
        void forWaves();
    
    ofSoundPlayer smoke;
    ofSoundPlayer smokeClick;
    
    SmokeSound();
    
    
};

#endif /* SmokeSound_hpp */
