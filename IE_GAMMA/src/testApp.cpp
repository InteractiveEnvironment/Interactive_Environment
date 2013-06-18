#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

	const vector<Ausgang*> KameraBlockAusgaenge = KameraBlock->ausgaenge();
	const vector<Eingang*> BildBlockEingaenge = BildBlock->eingaenge();

	BildBlockEingaenge[Ausgabeblock_Bild::IMAGE]->verbinden(*KameraBlockAusgaenge[Eingangsblock_Kamera::IMAGE]);

	cout << KameraBlock->text() << BildBlock->text();
}

//--------------------------------------------------------------
void testApp::update(){

    KameraBlock->update();
    BildBlock->update();
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
