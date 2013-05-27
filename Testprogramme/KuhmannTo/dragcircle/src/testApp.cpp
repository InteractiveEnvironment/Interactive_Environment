#include "testApp.h"

ofPoint imgPos;
ofPoint dist;
ofImage img;
int w,h;



//--------------------------------------------------------------
void testApp::setup(){


  img.loadImage("image.jpg");
    w = img.width;
    h = img.height;
    imgPos.x = (ofGetWidth()-w)/2;
    imgPos.y = (ofGetHeight()-h)/2;
}

//--------------------------------------------------------------
void testApp::update(){
   if(imgPos.x >= ofGetWindowWidth()-img.width/2)
    {
        imgPos.x = ofGetWindowWidth()-img.width/2;
    }
    if(imgPos.x <= img.width/2)
    {
        imgPos.x = img.width/2;
    }


    if(imgPos.y >= ofGetWindowHeight()-img.height/2)
    {
        imgPos.y = ofGetWindowHeight()-img.height/2;
    }
    if(imgPos.y <= img.height/2)
    {
        imgPos.y = img.height/2;
    }


}

//--------------------------------------------------------------
void testApp::draw(){

    img.draw(imgPos.x, imgPos.y, w,h);
    img.setAnchorPercent(0.5, 0.5);



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

 imgPos.x = mouseX - dist.x;
 imgPos.y = mouseY - dist.y;

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    dist.x = mouseX - imgPos.x;
    dist.y = mouseY - imgPos.y;




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
