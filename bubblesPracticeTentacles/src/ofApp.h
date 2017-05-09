#pragma once

#include "ofMain.h"
#include "Bubbles.hpp"
#include "BaseCircle.hpp"
#include "Waves.hpp"
#include "Smoke.hpp"
#include "Horror.hpp"
#include "Tentacle.hpp"
#include "Sound.hpp"
#include "SmokeSound.hpp"
#include "Buttons.hpp"

//ofColor globalColour;



class ofApp : public ofBaseApp{

    public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector <Bubbles> bubbles;
    vector <Smoke> smoke;
    vector <Tentacle> tentacles;
    //vector <ofVec2f> tent;
    
    BaseCircle baseCircle;
    Waves waves;
    Horror horror;
    
    Sound sound;
    //SmokeSound smokeSound;
    Buttons button;

    float HALF_HEIGHT = ofGetHeight()/2;
    float HALF_WIDTH = ofGetWidth()/2;
    float pointX;
    float pointY;
    
//    ofImage waterButton;
//    ofImage horrorButton;
//    ofImage smokeButton;
    
    ofShader shader;
    ofCamera cam;
    
    //ofSoundPlayer bubSound;

    
};
