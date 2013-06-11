#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(2);

//    block_Addierer.gebeEingang(0)->verbinde(block_Zufallszahl.gebeAusgang(0));  // Verbindung zwischen Eingangsblock_Zufallszahl (alias "block1") und Ausgabeblock_Konsole (alias block2) wird aufgebaut
//    block_Addierer.gebeEingang(1)->verbinde(block_Hochzaehler.gebeAusgang(0));  // indem der Zeiger auf den ersten Ausgang von block2 der verbinde-Methode von block1 übergeben wird
//    block_Konsole.gebeEingang(0)->verbinde(block_Addierer.gebeAusgang(0));
}

//--------------------------------------------------------------
void testApp::update(){

//    block_Zufallszahl.update();    // Es werden zyklisch alle Blockobjekte aktualisiert
//    block_Hochzaehler.update();
//    block_Addierer.update();
//    block_Konsole.update();

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
