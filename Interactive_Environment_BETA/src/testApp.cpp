#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    block2_Konsole.gebeEingang(0)->verbinde(block1_Zufallszahl.gebeAusgang(0)); // Verbindung zwischen Eingangsblock_Zufallszahl (alias "block1") und Ausgabeblock_Konsole (alias block2) wird aufgebaut
                                                                                // indem der Zeiger auf den ersten Ausgang von block2 der verbinde-Methode von block1 übergeben wird
}

//--------------------------------------------------------------
void testApp::update(){

    block1_Zufallszahl.update();    // Es werden zyklisch alle Blockobjekte aktualisiert
    block2_Konsole.update();
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
