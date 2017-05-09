
precision highp float;

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
    ofVec2f p1;
    ofVec2f p2;
    p1.set(ofGetMouseX(), ofGetMouseY());
    //p2.set(ofGetWidth()/2, ofGetHeight()/2);
    float field;
    float mouseX = ofGetMouseX();
    float mouseY = ofGetMouseY();
    
    float r = distance(gl_FragCoord.x, mouseX);// / mouseX;
    float g = gl_FragCoord.y;// / mouseY;
	float b = 1.0;
	float a = 1.0;
	gl_FragColor = vec4(r, g, b, a);
}
