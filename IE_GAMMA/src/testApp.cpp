#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(25);

    KameraBlock = new Eingangsblock_Kamera("KameraBlock");
    HintergrundBlock = new Eingangsblock_Bild("HintergrundBlock");

    SchnappschussBlock = new Verarbeitungsblock_Schnappschuss("SchnappschussBlock");
    BildsubstraktorBlock = new Verarbeitungsblock_Bildsubstraktion("BildsubstraktorBlock");
    BinarisierungsBlock = new Verarbeitungsblock_Binarisierung("BinarisierungsBlock");
    HintergrundersetzerBlock = new Verarbeitungsblock_Hintergrundersetzer("HintergrundersetzerBlock");

    BildBlock = new Ausgabeblock_Bild("Bildblock", 20, 20);

//  ALTERNATIVE METHODE:
//	const vector<Ausgang*> KameraBlockAusgaenge = KameraBlock->ausgaenge();
//	const vector<Eingang*> BildBlockEingaenge = BildBlock->eingaenge();
//	BildBlockEingaenge[Ausgabeblock_Bild::IMAGE]->verbinden(*KameraBlockAusgaenge[Eingangsblock_Kamera::IMAGE]);

    std::cout << "Verbindungen werden erstellt" << std::endl;
    SchnappschussBlock->eingaenge()[Verarbeitungsblock_Schnappschuss::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    BildsubstraktorBlock->eingaenge()[Verarbeitungsblock_Bildsubstraktion::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    BildsubstraktorBlock->eingaenge()[Verarbeitungsblock_Bildsubstraktion::BACKGROUND_IMAGE]->verbinden(*SchnappschussBlock->ausgaenge()[Verarbeitungsblock_Schnappschuss::IMAGE]);
    BinarisierungsBlock->eingaenge()[Verarbeitungsblock_Binarisierung::IMAGE]->verbinden(*BildsubstraktorBlock->ausgaenge()[Verarbeitungsblock_Bildsubstraktion::IMAGE]);

    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::MASKEN_IMAGE]->verbinden(*BinarisierungsBlock->ausgaenge()[Verarbeitungsblock_Binarisierung::IMAGE]);
    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::BACKGROUND_IMAGE]->verbinden(*HintergrundBlock->ausgaenge()[Eingangsblock_Bild::IMAGE]);

	BildBlock->eingaenge()[Ausgabeblock_Bild::IMAGE]->verbinden(*HintergrundersetzerBlock->ausgaenge()[Verarbeitungsblock_Hintergrundersetzer::IMAGE]);
	std::cout << "Alle Verbindungen wurden erstellt" << std::endl;

//	std::cout << KameraBlock->text() << BildBlock->text() << std::endl;
}

//--------------------------------------------------------------
void testApp::update(){

    KameraBlock->update();
    SchnappschussBlock->update();
    BildsubstraktorBlock->update();
    BinarisierungsBlock->update();
    HintergrundersetzerBlock->update();
    BildBlock->update();
}

//--------------------------------------------------------------
void testApp::draw(){

    BildBlock->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch (key){
        case ' ':
            SchnappschussBlock->trigger();
            break;
    }

    std::cout << "KeyPressed: " << key << std::endl;
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
