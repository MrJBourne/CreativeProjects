#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    ofGLWindowSettings settings;
    settings.setGLVersion(3,2);
    //ofSetupOpenGL(1024,768,OF_WINDOW);
    ofCreateWindow(settings);
    
    //ofSetupOpenGL(1024,768,OF_WINDOW);
	//ofSetupOpenGL(2880,1800,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
