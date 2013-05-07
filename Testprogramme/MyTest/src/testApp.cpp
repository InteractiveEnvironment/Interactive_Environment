//
//  
//  MyTest
//
//  Created by Bahar Ertem on 16.12.12.
//
//

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    ofSetFrameRate(30);
    
    xPos = ofGetWindowWidth()*0.5;
    yPos = ofGetWindowHeight()*0.5;
    xPos2 = ofGetWindowWidth()*0.5;
    yPos2 = ofGetWindowHeight()*0.5;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    xPos += (mouseX - xPos)*0.2;
    yPos += (mouseY - yPos)*0.2;
    xPos2 += (mouseX - xPos2)*0.1;
    yPos2 += (mouseY - yPos2)*0.1;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    ofSetColor(ofColor::blue);
    ofSetColor(255, 235, 3);
    ofFill();
    ofCircle(xPos, yPos, 40);   //Gesicht
    
    ofSetColor(0);
    ofCircle(xPos+15, yPos-10, 5);      //Augen
    ofCircle(xPos-15, yPos-10, 5);
    
    ofEllipse(xPos, yPos+20, 30, 5);    //Mund
    
    ofSetColor(247, 214, 177);
    ofCircle(xPos2, yPos2, 35);
    
    ofSetColor(0);
    ofCircle(xPos2+20, yPos2-30, 25);     //Ohren
    ofCircle(xPos2-20, yPos2-30, 25);
    
    ofSetColor(255);
    ofEllipse(xPos2+7, yPos2, 7, 15);        //Augen
    ofEllipse(xPos2-7, yPos2, 7, 15);
    ofSetColor(0);
    ofEllipse(xPos2+7, yPos2+1, 5, 5);
    ofEllipse(xPos2-7, yPos2+1, 5, 5);
    
    ofEllipse(xPos2, yPos2+10, 8, 4);    //Nase
    
    ofEllipse(xPos2, yPos2+20, 10, 3);  //Mund
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    xPos = ofRandom(ofGetWindowWidth());
    yPos = ofRandom(ofGetWindowHeight());
    xPos2 = ofRandom(ofGetWindowWidth());
    yPos2 = ofRandom(ofGetWindowHeight());
    
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