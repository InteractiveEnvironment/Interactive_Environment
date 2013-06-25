#pragma once

#include "ofMain.h"
#include "Ausgang.h"
#include "Eingang.h"

#include "Eingangsblock_Kamera.h"
#include "Eingangsblock_Bild.h"
#include "Verarbeitungsblock_Schnappschuss.h"
#include "Verarbeitungsblock_Bildsubstraktion.h"
#include "Verarbeitungsblock_Binarisierung.h"
#include "Verarbeitungsblock_Hintergrundersetzer.h"
#include "Ausgabeblock_Bild.h"

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

		void verbinden_0();
		void verbinden_1();
		void verbinden_2();
		void verbinden_3();

		Eingangsblock_Kamera * KameraBlock;
		Eingangsblock_Bild * HintergrundBlock;
		Verarbeitungsblock_Schnappschuss * SchnappschussBlock;
		Verarbeitungsblock_Bildsubstraktion * BildsubstraktorBlock;
		Verarbeitungsblock_Binarisierung * BinarisierungsBlock;
		Verarbeitungsblock_Hintergrundersetzer * HintergrundersetzerBlock;
		Ausgabeblock_Bild* BildBlock;
		Ausgabeblock_Bild* BildBlock_2;
		Ausgabeblock_Bild* BildBlock_3;

};
