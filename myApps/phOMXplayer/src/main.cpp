/*
#include "ofMain.h"
///#include "ofConstants.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"


//========================================================================
int main( ){

	ofAppNoWindow window;
///	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
///    ofSetupOpenGL(1024,768,OF_FULLSCREEN);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new ofApp());

}
*/
#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "ofApp.h"

//========================================================================
int main( ){
	auto window = make_shared<ofAppNoWindow>();
	auto app = make_shared<ofApp>();
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(window, app);
	ofRunMainLoop();

}
