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

    //std::cout << "Verbindungen werden erstellt" << std::endl;
    verbinden_0();
	//std::cout << "Alle Verbindungen wurden erstellt" << std::endl;

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
        case '0':
            verbinden_0();
            break;
        case '1':
            verbinden_1();
            break;
        case 357:
        case 359:
            BinarisierungsBlock->trigger(key);
            break;
        case 356:
        case 358:
            HintergrundBlock->trigger(key);
            break;
        case 'v':
        case 'V':
            KameraBlock->trigger(key);
            break;
        default:
            std::cout << "KeyPressed: " << key << std::endl;
    }

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

void testApp::verbinden_0(){
    BildBlock->eingaenge()[Ausgabeblock_Bild::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
}
void testApp::verbinden_1(){

    SchnappschussBlock->eingaenge()[Verarbeitungsblock_Schnappschuss::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    BildsubstraktorBlock->eingaenge()[Verarbeitungsblock_Bildsubstraktion::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    BildsubstraktorBlock->eingaenge()[Verarbeitungsblock_Bildsubstraktion::BACKGROUND_IMAGE]->verbinden(*SchnappschussBlock->ausgaenge()[Verarbeitungsblock_Schnappschuss::IMAGE]);
    BinarisierungsBlock->eingaenge()[Verarbeitungsblock_Binarisierung::IMAGE]->verbinden(*BildsubstraktorBlock->ausgaenge()[Verarbeitungsblock_Bildsubstraktion::IMAGE]);

    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::MASKEN_IMAGE]->verbinden(*BinarisierungsBlock->ausgaenge()[Verarbeitungsblock_Binarisierung::IMAGE]);
    HintergrundersetzerBlock->eingaenge()[Verarbeitungsblock_Hintergrundersetzer::BACKGROUND_IMAGE]->verbinden(*HintergrundBlock->ausgaenge()[Eingangsblock_Bild::IMAGE]);

	BildBlock->eingaenge()[Ausgabeblock_Bild::IMAGE]->verbinden(*HintergrundersetzerBlock->ausgaenge()[Verarbeitungsblock_Hintergrundersetzer::IMAGE]);

}
