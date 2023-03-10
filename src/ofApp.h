#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "virus.h"
#include <vector>

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

        // webcam input properties
        ofVideoGrabber vidGrabber;
				vector<ofVideoDevice> devices;
				int currentDeviceId;

        // camera dimensions
        int camWidth;
        int camHeight;

        // current video frame
        ofxCvColorImage image;

        // current video frame in grayscale
        ofxCvGrayscaleImage grayImage;

        // previous video frame in grayscale
        ofxCvGrayscaleImage grayImagePrev;

        // absolute difference of current and previous frame
        ofxCvGrayscaleImage diff;

        // amplified difference of current and previous frame
        ofxCvFloatImage diffFloat;

        // buffer image: stores all differences in movement, with damping
        ofxCvFloatImage bufferFloat;

        // virus containers
        vector<Virus> viruses;
        vector<Virus> dyingViruses;

        // properties to keep track of time & difficulty
        float currentTime;
        float delay;
				float decrementDelay;
				float delayLimit;
				int criticalMass;

        // sound and text properties
        ofSoundPlayer virusKillSound;
        ofSoundPlayer gameOverSound;
        ofSoundPlayer shortBeep;
        ofSoundPlayer longBeep;
				ofSoundPlayer soundTrack;
        ofTrueTypeFont eightBitWonder12;
        ofTrueTypeFont eightBitWonder32;
        ofTrueTypeFont eightBitWonder64;
				ofTrueTypeFont eightBitWonder96;
				float textWidth;
				float textHeight;

        // game properties
        bool gameOver;
        bool countDown;
        int score;
				bool startGame;
				float countDownStartTime;
				bool withinFrame;
        bool beep1played;
        bool beep2played;
        bool beep3played;
        bool longBeepPlayed;
};
