//
//  WaveSound.cpp
//  bubblePractice
//
//  Created by D l Samual on 29/04/2017.
//
//

#include "Sound.hpp"

Sound::Sound(){
    
}

void Sound::waveSoundClick(){
    
    bubClick.setMultiPlay(true);
    bubClick.setLoop(false);
    bubClick.play();
    
}

void Sound:: soundSetup(){
    
    bub.load("sounds/deepBubble.wav");
    //bub.setVolume(0.75f);
    bub.setMultiPlay(false);
    bub.setLoop(true);
    bub.play();
    bub.setPaused(true);
    
    bubClick.load("sounds/bubClick.wav");
    bubClick.setVolume(0.1f);
    bubClick.setMultiPlay(true);
    bubClick.setLoop(false);
    
    smoke.load("sounds/Car.wav");
    //smoke.setVolume(0.75f);
    smoke.setMultiPlay(false);
    smoke.setLoop(true);
    smoke.play();
    smoke.setPaused(true);
    
    atmos.load("sounds/atmosphere.wav");
    atmos.setMultiPlay(false);
    atmos.setLoop(true);
    atmos.play();
    atmos.setPaused(true);
    
    horror2.load("sounds/horror1.wav");
    horror2.setLoop(true);
    horror2.setMultiPlay(false);
    horror2.play();
    horror2.setPaused(true);
    
    horror0.load("sounds/horror0.wav");
    horror0.setLoop(true);
    horror0.setMultiPlay(false);
    horror0.play();
    horror0.setPaused(true);
    
    car.load("sounds/Car.wav");
    car.setLoop(true);
    car.setMultiPlay(false);
    car.play();
    car.setPaused(true);
    
    fire.load("sounds/fire.wav");
    fire.setLoop(true);
    fire.setMultiPlay(false);
    fire.play();
    fire.setPaused(true);
    
    waterScene = false;
    smokeScene = false;
    horrorScene = false;
    waterSound = false;
    smokeSounds = false;
    horrorSound = false;
    
}

//Might look overly complicated but these are just functions to tell the program what sounds to play
void Sound::water(){
    
    bub.setPaused(false);
    
    float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
    
    float soundVolume = ofMap(distance, 0, 350, 1.0f, 0.1f);
    
    bub.setVolume(soundVolume);
    
}
void Sound::forBubbles(){ //-------THIS WORKS!!!!!!!!!
    
    if((waterScene == true) && (horrorSound == false)){
        
        water();

    } else  if ((waterScene && horrorSound) == true){
        
//adding sound
        water();
        atmos.setPaused(false);
        
        float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
        float soundVolume = ofMap(distance, 0, 300, 1.0f, 0.1f);
        
        horror0.setPaused(false);
        horror0.setVolume(soundVolume);
        
        float distance2 = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
        float soundVolume2 = ofMap(distance2, 0, 700, 0.1f, 2.0f);
        
        horror2.setPaused(false);
        horror2.setVolume(soundVolume2);
        
    } if (waterScene == false){
        
        bub.setPaused(true);
        
    }
    
    if(horrorSound ==false){
        atmos.setPaused(true);
        horror0.setPaused(true);
        horror2.setPaused(true);
        fire.setPaused(true);
    }
}

//Good template now
void Sound::forSmoke(){
    
    if ((smokeScene == true) && (horrorSound == false)){
        
        car.setPaused(false);
        
        float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
        float soundVolume = ofMap(distance, 0, 700, 0.1f, 1.0f);
        
        car.setSpeed(soundVolume);
        
    } else if (smokeScene && horrorSound == true){
        {
            car.setPaused(true);
            fire.setPaused(false);
            //--------------------
            atmos.setPaused(false);
            
            float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
            float soundVolume = ofMap(distance, 0, 300, 1.0f, 0.1f);
            
            //horror0.setPaused(false);
            horror0.setVolume(soundVolume);
            
            float distance2 = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
            float soundVolume2 = ofMap(distance2, 0, 700, 0.0f, 0.2f);
            
            //horror2.setPaused(false);
            fire.setVolume(soundVolume2);
            
        }
        
    } else if (smokeScene == false){
        
        car.setPaused(true);
        fire.setPaused(true);
        
        }
    }

//void Sound::forHorror(){
//    
//    //soundVolumes fade one sound in and the other out when mouse moves away from the screen
//    
//    if(horrorSound == true){
//        
//        atmos.setPaused(false);
//        
//        float distance = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
//        float soundVolume = ofMap(distance, 0, 300, 1.0f, 0.1f);
//        
//        horror0.setPaused(false);
//        horror0.setVolume(soundVolume);
//        
//        float distance2 = ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5);
//        float soundVolume2 = ofMap(distance2, 0, 700, 0.1f, 2.0f);
//        
//        horror2.setPaused(false);
//        horror2.setVolume(soundVolume2);
//
//    } else {
//        
//    }
//    
//}
