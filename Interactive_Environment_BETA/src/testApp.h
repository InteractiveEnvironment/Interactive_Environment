#pragma once

#include "ofMain.h"

#include "Block.h"
#include "VerarbeitungsBlock_Addierer.h"
#include "EingangsBlock_Zufallszahl.h"
#include "EingangsBlock_Hochzaehler.h"
#include "Ausgabeblock_Konsole.h"

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
//        EingangsBlock_Zufallszahl block_Zufallszahl;
//        EingangsBlock_Hochzaehler block_Hochzaehler;
//        VerarbeitungsBlock_Addierer block_Addierer;
//        AusgabeBlock_Konsole block_Konsole;

};
