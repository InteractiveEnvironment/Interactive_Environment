#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(25);

    IMAGE_HEIGHT = 240;
    IMAGE_WIDTH = 320;

    /** Videoeingangsblock Anfang setup */
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(IMAGE_WIDTH,IMAGE_HEIGHT);
    /** Videoeingangsblock Ende setup */

    /** SW Umwandlungsblock Anfang setup*/

    /** SW Umwandlungsblock Ende setup*/

    /** Braucht jeder Block, der Bilder verarbeitet */
    image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    bwImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    backgroundShot.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    substractedImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    binaryImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    newBackground.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    newBackground.loadImage("lake_of_fire.jpg");
    newBackground.reloadTexture();

    finalImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
    /** Videoeingangsblock Anfang update */
    vidGrabber.update();
    if (vidGrabber.isFrameNew()){
         unsigned char *pixels = vidGrabber.getPixels();
         image.setFromPixels(pixels,IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    }
    /** Videoeingangsblock Ende update */

    /** SW Umwandlungsblock Anfang update*/
    bwImage = image;
    bwImage.setImageType(OF_IMAGE_GRAYSCALE);
    /** SW Umwandlungsblock Ende update*/

    /** Image Substractorblock Anfang update **/
    for(int s=0; s<bwImage.getPixelsRef().size(); s++){
        substractedImage.getPixelsRef()[s] = std::abs( bwImage.getPixelsRef()[s] - backgroundShot.getPixelsRef()[s] );
    }
    substractedImage.reloadTexture();
    /** Image Substractorblock Ende update **/

    /**Binarisierungsblock Anfang update **/
    for(int s=0; s<binaryImage.getPixelsRef().size(); s++){
        binaryImage.getPixelsRef()[s] = substractedImage.getPixelsRef()[s] > 50 ? 255 : 0;
    }
    binaryImage.reloadTexture();
    /**Binarisierungsblock Ende update **/

    /**Bildaddierungsblock Anfang update **/
    for(int s=0, b=0; s<finalImage.getPixelsRef().size(); s+=3, b++){
        for(int p=0; p<3; p++){
            finalImage.getPixelsRef()[s+p] = binaryImage.getPixelsRef()[b] = 0 ? newBackground.getPixelsRef()[s+p] : image.getPixelsRef()[s+p];
        }
    }
    finalImage.reloadTexture();
    /**Bildaddierungsblock Ende update **/

}

//--------------------------------------------------------------
void testApp::draw(){

    /** Videoausgabeblock Anfang draw */
    image.draw(20, 20);
    bwImage.draw(IMAGE_WIDTH+30,20);
    backgroundShot.draw(2*(IMAGE_WIDTH+30), 20);
    substractedImage.draw(20, IMAGE_HEIGHT+30);
    binaryImage.draw(IMAGE_WIDTH+30, IMAGE_HEIGHT+30);
    newBackground.draw(2*(IMAGE_WIDTH+30), IMAGE_HEIGHT+30);

    finalImage.draw(20, 2*(IMAGE_HEIGHT+30));
    /** Videoausgabeblock Ende draw */

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    std::cout << "Key pressed: " << key << std::endl;
    switch (key){
        case ' ':
            backgroundShot = bwImage;
            break;
        default:
            std::cout << "Meep" << std::endl;
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
