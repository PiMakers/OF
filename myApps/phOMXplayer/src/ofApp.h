#pragma once

#include "ofMain.h"
///#include "puBHubPlayer.h"
#include "omxplayerOrig.h"

#warning BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB;
///*H   #include "OmxPubHubPlayer.h"
/// #include "ofxPubHubPlayer.h"
/// #include "ofxPubHubBasePlayer.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void pexit();

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

        phOMXplayer* php = new phOMXplayer;
        int delta_time, current_time, prev_time;

};
