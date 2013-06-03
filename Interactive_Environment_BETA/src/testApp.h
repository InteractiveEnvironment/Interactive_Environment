#pragma once

#include "ofMain.h"

#include "Block.h"
#include "VerarbeitungsBlock_Addierer.h"
#include "EingangsBlock_Zufallszahl.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    private:
        EingangsBlock_Zufallszahl block1;

};
