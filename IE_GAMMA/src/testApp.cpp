#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(25);
    //ofSetLogLevel(OF_LOG_SILENT); //DEAKTIVIERT ofLog !!

    KameraBlock = new Eingangsblock_Kamera("KameraBlock");
    HintergrundBlock = new Eingangsblock_Bild("HintergrundBlock");

    SchnappschussBlock = new Verarbeitungsblock_Schnappschuss("SchnappschussBlock");
    BildsubstraktorBlock = new Verarbeitungsblock_Bildsubstraktion("BildsubstraktorBlock");
    BinarisierungsBlock = new Verarbeitungsblock_Binarisierung("BinarisierungsBlock");
    HintergrundersetzerBlock = new Verarbeitungsblock_Hintergrundersetzer("HintergrundersetzerBlock");

    BildBlock = new Ausgabeblock_Bild("Bildblock", 0, 0);

    //std::cout << "Verbindungen werden erstellt" << std::endl;
    verbinden_0();
	//std::cout << "Alle Verbindungen wurden erstellt" << std::endl;
	isRunning = true;

}

//--------------------------------------------------------------
void testApp::update(){

    if (isRunning){
        KameraBlock->update();
        SchnappschussBlock->update();
        BildsubstraktorBlock->update();
        BinarisierungsBlock->update();
        HintergrundersetzerBlock->update();
        BildBlock->update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    if (isRunning){
        BildBlock->draw();
    }
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
        case '2':
            verbinden_2();
            break;
        case '3':
            verbinden_3();
            break;
        case '4':
            verbinden_4();
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
            //std::cout << "KeyPressed: " << key << std::endl;
            break;
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

    //BildBlock->eingaenge()[Ausgabeblock_Bild::IMAGE]->verbinden(*KameraBlock->ausgaenge()[Eingangsblock_Kamera::IMAGE]);
    BildBlock->verbinde(Ausgabeblock_Bild::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
}
void testApp::verbinden_1(){

    SchnappschussBlock->verbinde(Verarbeitungsblock_Schnappschuss::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildBlock->verbinde(Ausgabeblock_Bild::IMAGE, SchnappschussBlock, Verarbeitungsblock_Schnappschuss::IMAGE);
}

void testApp::verbinden_2(){
    SchnappschussBlock->verbinde(Verarbeitungsblock_Schnappschuss::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::BACKGROUND_IMAGE, SchnappschussBlock, Verarbeitungsblock_Schnappschuss::IMAGE);
    BildBlock->verbinde(Ausgabeblock_Bild::IMAGE, BildsubstraktorBlock, Verarbeitungsblock_Bildsubstraktion::IMAGE);
}

void testApp::verbinden_3(){
    SchnappschussBlock->verbinde(Verarbeitungsblock_Schnappschuss::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::BACKGROUND_IMAGE, SchnappschussBlock, Verarbeitungsblock_Schnappschuss::IMAGE);
    BinarisierungsBlock->verbinde(Verarbeitungsblock_Binarisierung::IMAGE, BildsubstraktorBlock, Verarbeitungsblock_Bildsubstraktion::IMAGE);
    BildBlock->verbinde(Ausgabeblock_Bild::IMAGE, BinarisierungsBlock, Verarbeitungsblock_Binarisierung::IMAGE);
}

void testApp::verbinden_4(){

    SchnappschussBlock->verbinde(Verarbeitungsblock_Schnappschuss::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    BildsubstraktorBlock->verbinde(Verarbeitungsblock_Bildsubstraktion::BACKGROUND_IMAGE, SchnappschussBlock, Verarbeitungsblock_Schnappschuss::IMAGE);
    BinarisierungsBlock->verbinde(Verarbeitungsblock_Binarisierung::IMAGE, BildsubstraktorBlock, Verarbeitungsblock_Bildsubstraktion::IMAGE);

    HintergrundersetzerBlock->verbinde(Verarbeitungsblock_Hintergrundersetzer::IMAGE, KameraBlock, Eingangsblock_Kamera::IMAGE);
    HintergrundersetzerBlock->verbinde(Verarbeitungsblock_Hintergrundersetzer::MASKEN_IMAGE, BinarisierungsBlock, Verarbeitungsblock_Binarisierung::IMAGE);
    HintergrundersetzerBlock->verbinde(Verarbeitungsblock_Hintergrundersetzer::BACKGROUND_IMAGE, HintergrundBlock, Eingangsblock_Bild::IMAGE);

	BildBlock->verbinde(Ausgabeblock_Bild::IMAGE, HintergrundersetzerBlock, Verarbeitungsblock_Hintergrundersetzer::IMAGE);

}

void testApp::exit(){
    isRunning = false;
    std::cout << "exiting programm calling destructors" << std::endl;
    //delete BildsubstraktorBlock;
    delete KameraBlock;
    delete HintergrundBlock;
    delete SchnappschussBlock;
    delete BinarisierungsBlock;
    delete HintergrundersetzerBlock;
    delete BildBlock;
}
