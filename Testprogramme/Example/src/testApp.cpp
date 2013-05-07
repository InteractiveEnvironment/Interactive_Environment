#include "testApp.h"

//-Erste Versuche: drei kreise Naty
void testApp::setup(){
	
	ofSetFrameRate(20);
    
    xPos = ofGetWindowWidth()*0.10;
    yPos = ofGetWindowHeight()*0.10;
}

//--------------------------------------------------------------
void testApp::update(){
    
	xPos += (mouseX - xPos)*0.5;
	yPos += (mouseY - yPos)*0.5;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofBackground(19,10,40);
    
    ofSetColor(ofColor::red);
    ofFill();
	ofCircle(xPos,yPos,100,70);
    
	ofSetColor(ofColor::blue);
	ofCircle(xPos,yPos,10,7);
    
	ofSetColor(ofColor::yellow);
	ofCircle (xPos+10,yPos-10,10,7);
    
    
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
    
	xPos = ofRandom(ofGetWindowWidth());
    yPos = ofRandom(ofGetWindowHeight());
    
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
