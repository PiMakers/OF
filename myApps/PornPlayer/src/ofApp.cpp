#include "ofApp.h"

bool bPaused = true;
int i = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < pps.numRooms; i++) {
    pps.ofxPPlayers[i]->updatePorn();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < pps.numRooms; i++) {
        pps.ofxPPlayers[i]->drawPorn();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_F1) {
        bPaused = ! bPaused;
        if (pps.ofxPPlayers[0]) pps.ofxPPlayers[0]->setPaused(bPaused);
        if (pps.ofxPPlayers[1]) pps.ofxPPlayers[1]->setPaused(!bPaused);
        ofLogNotice("F2 pressed!!!") << bPaused << "pps[0] IS_PAUSED?: " << ofToString(pps.ofxPPlayers[0]->isPaused());
        }
    if (key == OF_KEY_F2) {
        bPaused = ! bPaused;
        if (pps.ofxPPlayers[1]) pps.ofxPPlayers[1]->setPaused(bPaused);
        ofLogNotice("F2 pressed!!!") << bPaused << "pps[0] IS_PAUSED?: " << ofToString(pps.ofxPPlayers[0]->isPaused());
        }
    if (key == 'f') {
        ofToggleFullscreen();
        }
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
    if (button == 2) {
///        pp.setPaused(true);
    }
    else if (button == 1) {
        pps.ofxPPlayers[0]->setPaused(true);
    }
    else {
///        pp.setAnchorPoint( pp.getWidth()/2-x, pp.getHeight()/2-y);
///        pp.setPaused(false);
        pps.ofxPPlayers[0]->setPaused(false);
    }
    ofLogNotice("Button pressed!!! No.") << button;
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
