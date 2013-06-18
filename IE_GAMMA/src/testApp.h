#pragma once

#include "ofMain.h"
#include "Eingangsblock_Kamera.h"
#include "Ausgabeblock_Bild.h"
#include "Ausgang.h"
#include "Eingang.h"

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

		Eingangsblock_Kamera * KameraBlock = new Eingangsblock_Kamera("KameraBlock");
		Ausgabeblock_Bild* BildBlock = new Ausgabeblock_Bild("Bildblock");

};
