#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    
#ifdef TARGET_OPENGLES
    //shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        //shader.load("shadersGL2/shader");
    }
    //shader.load("shadersGL3/shader");
#endif
    
    ofSetFrameRate(60);
    cam.setPosition(0,0,750);
    //ofHideCursor();
    
    baseCircle.setup();
    waves.setup();
    horror.setup();
    sound.soundSetup();
    button.setup();

    //setup tentacles in bigger circle circumference
        for(int i = 0; i < horror.circleResolution; i += 80){
            Tentacle tentacle;
            tentacle.setup(waves.circle[i].x*2, waves.circle[i].y*2);
            //tentacle.setup(ofGetWidth()/2, ofGetHeight()/2);
            tentacles.push_back(tentacle);
    }
    //cam.setNearClip(0);
    //cam.setFarClip(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    baseCircle.update();
    
    if(sound.smokeScene == true){
        
            for(int i = 0; i < smoke.size(); i++){
                smoke[i].moveBubble();
            
                //if(smoke[i].colDist.r < 2){-----------//delete smoke when it turns black
                if(smoke[i].colour.r < 2){
                    smoke.erase(smoke.begin()+i);
                }
            }
    } else if(sound.waterScene == true){
        
            waves.update();
        
            for(int i = 0; i < bubbles.size(); i++){
            bubbles[i].moveBubble();
            //if the life/size of the bubble is smaller than 0 delete that bubble
                //if(bubbles[i].life < 0){
                if(bubbles[i].location.y <-ofGetHeight()/2){
                bubbles.erase(bubbles.begin()+i);
            }
        }
    }
    
    for(int i = 0; i < tentacles.size(); i++){
        tentacles[i].reachSegments(ofGetMouseX()-ofGetWidth()/2, ofGetMouseY()-ofGetHeight()/2);
        tentacles[i].positionSegments();
    }
    
    sound.forBubbles();
    sound.forSmoke();
    //sound.forHorror();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){

    //glLineWidth(6); It's a shame that this doesnt bloody work.
    cam.begin();
    ofScale(1, -1, 1);
    ofBackground(0);
    
    //if horror and water class are running, use shader and change colours
    if((sound.waterScene && sound.horrorSound) == true){
        
        shader.begin();
        float mx = mouseX;
        float my = mouseY;
        shader.setUniform2f("mouse", mx/150, (-my/150)+6);//+4.5);100//9
        //ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofDrawRectangle(-ofGetWidth()/2, -ofGetHeight()/2, ofGetWidth(), ofGetHeight()); //because cam is being used
        shader.end();
        
        
        for(int i = 0; i < tentacles.size(); i ++){
            tentacles[i].draw();//add tentacles
        }
    }
    
    if(sound.horrorSound ==  true){
        
        for(int i = 0; i < smoke.size(); i++){
            smoke[i].colour = smoke[i].colDist;
        }
    }

    //--------------------------------------------WATER
    
    if(sound.waterScene==true){

            waves.draw();
        
            for(int i = 0; i <bubbles.size(); i++){
            bubbles[i].drawBubble();
            }
        
        //drawing bubbles around the circumference of circle when mouse is within range
        for(int i = 0; i < waves.circleResolution; i+=30){
            
            //create distance
            ofVec2f p2(waves.circle[i].x, waves.circle[i].y);
            ofVec2f p1(ofGetMouseX()-HALF_WIDTH-225, ofGetMouseY()-HALF_HEIGHT-75);
            float bias = p1.distance(p2);
            
            float X = ofRandom(-20, 20);
            float Y = ofRandom(-20, 20);
            
            //if mouse is within the range of the circle, create bubbles
            if(bias<200){
                
                float size = ofRandom(20);
                
                Bubbles bubble;
                bubble.setup(waves.circle[i].x+X, waves.circle[i].y+Y, size);
                bubbles.push_back(bubble);
            }
        }
    }
    
        //---------------------------------------------SMOKE
    
    if(sound.smokeScene==true){
        
        for(int i = 0; i < baseCircle.circleResolution; i+=40){
            Smoke smokey;
            smokey.setup(baseCircle.newCircle[i].x, baseCircle.newCircle[i].y, 20);
            smoke.push_back(smokey);
        }
        for(int i = 0; i < smoke.size(); i++){
            smoke[i].drawBubble();
        }
        baseCircle.draw();
    }
    
    if(sound.horrorSound == true){
        
        waves.waveColour = (0,0,0);
        
        for(int i = 0; i < bubbles.size(); i++){
            bubbles[i].colour.a = 150;
            bubbles[i].colour = 0;
        }
        
        for(int i = 0; i < tentacles.size(); i++){
            tentacles[i].colour = (0);
        }
        
    } else {
        waves.waveColour = (10,100,240);
    }
    button.all();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    float randomX = ofRandom(-50, 50);
    float randomY = ofRandom(-50, 50);
    float size = ofRandom(10, 20);
    
    //creating bubbles and smoke at mouse location
    if(sound.waterScene==true){
    Bubbles bubble;
    bubble.setup(ofGetMouseX()+randomX-HALF_WIDTH-200, ofGetMouseY()+randomY-HALF_HEIGHT-100, size);
    //bubbles.push_back(bubble);
    }
    
    if(sound.smokeScene==true){
    Smoke smokey;
    smokey.setup(ofGetMouseX()-HALF_WIDTH-200, ofGetMouseY()-HALF_HEIGHT-100, size);
    smoke.push_back(smokey);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //-----just 'buttons' for switching scenes
    if(ofDist(ofGetMouseX(), ofGetMouseY(), 150, 150) < 100 ){
        
        sound.waterScene = true;
        sound.smokeScene = false;

    } else if (ofDist(ofGetMouseX(), ofGetMouseY(), 150, 300) < 100 ){
     
        sound.waterScene = false;
        sound.smokeScene = true;

    }
    
    //---------------------------------------buttons for switching between horror versions

    if(ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()-150, 150) < 100 ){
        
        sound.horrorSound = true;
        
    } else if (ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()-150, 300) < 100){
        
        sound.horrorSound = false;
    
    }
    //creating bubbles around the circumference of circle
    if(sound.waterScene==true){
        
    for(int i = 0; i < waves.circleResolution; i+=2){
        
            //if(ofDist(ofGetMouseX(), ofGetMouseY(), ofGetWidth()/2, ofGetHeight()*0.5) < 200 ){
                //sound.soundClick();
                    
                float randomX = ofRandom(-3, 3);
                float randomY = ofRandom(-3, 3);
                float size = ofRandom(20, 30);

                Bubbles bubble;
                bubble.setup(waves.circle[i].x+randomX, waves.circle[i].y+randomY, size);
                bubbles.push_back(bubble);
            //}
        }
    }
     //creating smoke around the circumference of circle
    if(sound.smokeScene==true){
        
    for(int i = 0; i < baseCircle.circleResolution; i+=10){
        Smoke smokey;
        smokey.setup(baseCircle.circle[i].x, baseCircle.circle[i].y, 20);
        smoke.push_back(smokey);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
