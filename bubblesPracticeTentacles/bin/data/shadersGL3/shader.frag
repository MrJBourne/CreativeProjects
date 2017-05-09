#version 150

out vec4 outputColor;

uniform vec2 mouse;
//uniform vec2 resolution;

void main()
{

    vec2 mouse_distance = mouse - (gl_FragCoord.xy / 150);//100
    

    float red = 1.0 - length(mouse_distance);
    float green = 1.0 - length(mouse_distance);
    float blue = 1.0 - length(mouse_distance);
    
	outputColor = vec4(red, green, blue, 1.0);
    
}

/*
 #version 150
 
 out vec4 outputColor;
 
 void main()
 {
 // gl_FragCoord contains the window relative coordinate for the fragment.
 // we use gl_FragCoord.x position to control the red color value.
 // we use gl_FragCoord.y position to control the green color value.
 // please note that all r, g, b, a values are between 0 and 1.
 
 float windowWidth = 1024.0;
 float windowHeight = 768.0;
 
 float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = 1.0;
	float a = 1.0;
	outputColor = vec4(r, g, b, a);
 }
*/
