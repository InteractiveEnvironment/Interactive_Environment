#pragma once

#include "ofMain.h"
#include "../include/BackgroundSubst.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void setNewBackground();
        void addNewBackground();

        BackgroundSubst backsubsBlock;
        ofImage resultFrame;
        ofImage videoFrame;
		ofVideoGrabber  vidGrabber;
		int camWidth;
		int camHeight;
};
