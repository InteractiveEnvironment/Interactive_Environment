#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    /** Videoeingangsblock Anfang setup */
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
    /** Videoeingangsblock Ende setup */

    /** Braucht jeder Block, der Bilder verarbeitet */
    image.allocate(320,240,OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void testApp::update(){
    /** Videoeingangsblock Anfang update */
    vidGrabber.update();
    if (vidGrabber.isFrameNew()){
         unsigned char *pixels = vidGrabber.getPixels();
         image.setFromPixels(pixels,320,240,OF_IMAGE_COLOR);

    }
    /** Videoeingangsblock Ende update */

}

//--------------------------------------------------------------
void testApp::draw(){

/** Videoausgabeblock Anfang draw */
image.draw(20,20);
/** Videoausgabeblock Ende draw */

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
