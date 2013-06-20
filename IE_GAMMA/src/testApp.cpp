#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(25);

    KameraBlock = new Eingangsblock_Kamera("KameraBlock");
    BildBlock = new Ausgabeblock_Bild("Bildblock");

	const vector<Ausgang*> KameraBlockAusgaenge = KameraBlock->ausgaenge();
	const vector<Eingang*> BildBlockEingaenge = BildBlock->eingaenge();

	BildBlockEingaenge[Ausgabeblock_Bild::IMAGE]->verbinden(*KameraBlockAusgaenge[Eingangsblock_Kamera::IMAGE]);

	std::cout << KameraBlock->text() << BildBlock->text() << std::endl;
}

//--------------------------------------------------------------
void testApp::update(){

//    std::cout << "U P D A T E" << std::endl;
    KameraBlock->update();
}

//--------------------------------------------------------------
void testApp::draw(){
//    std::cout << "D R A W" << std::endl;
    BildBlock->update();
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
