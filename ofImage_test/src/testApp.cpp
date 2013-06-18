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
    //backgroundShot.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    backgroundShot.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    //substractedImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    substractedImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    //binaryImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    binaryImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    bwBinaryImage.allocate(IMAGE_WIDTH, IMAGE_HEIGHT,OF_IMAGE_GRAYSCALE);
    newBackground.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
    newBackground.loadImage("lake_of_fire.jpg");
    newBackground.reloadTexture();
    finalImage.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);

    backgroundShot = image;
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

    /** Image Substractorblock Anfang update **/
    for(int s=0; s<image.getPixelsRef().size(); s++){
        substractedImage.getPixelsRef()[s] = std::abs( image.getPixelsRef()[s] - backgroundShot.getPixelsRef()[s] );
    }
    substractedImage.reloadTexture();
    /** Image Substractorblock Ende update **/

    /** SW Umwandlungsblock Anfang update*/
    bwImage = substractedImage;
    bwImage.setImageType(OF_IMAGE_GRAYSCALE);
    /** SW Umwandlungsblock Ende update*/

    /**Binarisierungsblock Anfang update **/
    for(int s=0; s<binaryImage.getPixelsRef().size(); s++){
        binaryImage.getPixelsRef()[s] = substractedImage.getPixelsRef()[s] > 35 ? 255 : 0;
    }
    binaryImage.reloadTexture();
    /**Binarisierungsblock Ende update **/

    /**BW Binarisierungsblock Anfang update **/
    for(int s=0; s<bwBinaryImage.getPixelsRef().size(); s++){
        bwBinaryImage.getPixelsRef()[s] = bwImage.getPixelsRef()[s] > 35 ? 255 : 0;
    }
    bwBinaryImage.reloadTexture();
    /**BW Binarisierungsblock Ende update **/

    /**Bildaddierungsblock Anfang update **/
    for(int s=0, b=0; s<finalImage.getPixelsRef().size(); s+=3, b++){
        if(binaryImage.getPixelsRef()[s] > 0
           || binaryImage.getPixelsRef()[s+1] > 0
           || binaryImage.getPixelsRef()[s+2] > 0){
            for(int i=0; i<3; i++){
                finalImage.getPixelsRef()[s+i] = image.getPixelsRef()[s+i];
            }
        }else{
            for(int i=0; i<3; i++){
                finalImage.getPixelsRef()[s+i] = newBackground.getPixelsRef()[s+i];
            }
        }
    }
    finalImage.reloadTexture();
    /**Bildaddierungsblock Ende update **/

}

//--------------------------------------------------------------
void testApp::draw(){

    /** Videoausgabeblock Anfang draw */
    image.draw(20, 20);
    backgroundShot.draw(20, IMAGE_HEIGHT+20+10);
    newBackground.draw(20, 2*(IMAGE_HEIGHT+10)+20);

    bwImage.draw(IMAGE_WIDTH+20+10,20);
    bwBinaryImage.draw(IMAGE_WIDTH+20+10, IMAGE_HEIGHT+20+10);


    substractedImage.draw(2*(IMAGE_WIDTH+10)+20, 20);
    binaryImage.draw(2*(IMAGE_WIDTH+10)+20, IMAGE_HEIGHT+20+10);

    finalImage.draw(2*(IMAGE_WIDTH+10)+20, 2*(IMAGE_HEIGHT+10)+20);
    /** Videoausgabeblock Ende draw */

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    std::cout << "Key pressed: " << key << std::endl;
    switch (key){
        case ' ':
            backgroundShot = image;
            break;
        case 'v':
        case 'V':
            vidGrabber.videoSettings();
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
