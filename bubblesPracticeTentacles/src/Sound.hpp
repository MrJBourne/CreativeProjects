//
//  WaveSound.hpp
//  bubblePractice
//
//  Created by D l Samual on 29/04/2017.
//
//

#ifndef Sound_hpp
#define Sound_hpp

#include <stdio.h>
#include "ofMain.h"

class Sound{
    
private:
    
public:
    
    void waveSoundClick();
    
    //-------------------------Setup all sounds
    
    void soundSetup();
    
    //-------------------------Scene sounds
    
    void forBubbles();
    void forSmoke();
    //void forHorror();
    
    void water();
    
    ofSoundPlayer bub;
    ofSoundPlayer bubClick;
    
    ofSoundPlayer smoke;
    ofSoundPlayer smokeClick;
    ofSoundPlayer fire;
    
    ofSoundPlayer horror0;
    ofSoundPlayer horror2;
    ofSoundPlayer atmos;
    
    ofSoundPlayer car; //replace car sound with smoke?
    
    Sound();
    
    bool waterScene;
    bool smokeScene;
    bool horrorScene;
    
    bool waterSound;
    bool smokeSounds;
    bool horrorSound;
    
};

#endif /* WaveSound_hpp */
