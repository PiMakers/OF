#include "ofApp.h"

#define TIME_BEFORE_EXIT 100

//--------------------------------------------------------------
void ofApp::setup(){
/// char* argv[] = { "OmxPlayerOF", "--loop",/* "-r", "-b", */"--layer", "1", "--alpha", "60", "--win", "300,0,512,400", "/mnt/LinuxData/Videos/00Timecoded_Big_bunny_1.mov"  };
/// php->omxPlayerCli("/mnt/LinuxData/Videos/00Timecoded_Big_bunny_1.mov");

    char* argv[] = {"OmxPlayerOF", "--win", "300,0,512,400", "/mnt/LinuxData/Videos/00Timecoded_Big_bunny_1.mov"};
    int argc = sizeof (argv)/4;

    if ( php->omxplayerOrig (argc, argv)) {
        ofLogError(__func__) << "MEEEE...!!!";
    }
    else ofLogError(__func__) << "EVERYTHING_WILL_BE_ALLRIGHT...";
    prev_time = ofGetElapsedTimeMillis()/1000;
}

//--------------------------------------------------------------
void ofApp::update(){
/*
    current_time = ofGetElapsedTimeMillis()/1000;
    delta_time = current_time - prev_time;
    cout << "\rDELTA_TIME: " << delta_time << "s";
    if (delta_time < TIME_BEFORE_EXIT ) {
///    cout << "\r" << (TIME_BEFORE_EXIT - delta_time) << "s           " << delta_time << "s";
    }
    else {
       pexit();
    }
*/

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::pexit(){
    if ( php) {
        delete php;
        php = NULL;
        ofLogError(__func__) << "#####################";
    }
    else ofLogError(__func__) << "%%%%%%%%%%%%%%%%%%%#";
    exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofLogError(__func__) << "key pressed: " << key;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
