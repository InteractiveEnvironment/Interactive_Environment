#include "testApp.h"

//B A C K G R O U N D S U B S T R A C T I O N - TEST APP

//--------------------------------------------------------------
void testApp::setup()
{
    camWidth 		= 640;
    camHeight 		= 480;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    setNewBackground();
    resultFrame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void testApp::update()
{
    vidGrabber.update();
    if(vidGrabber.isFrameNew())
    {
        videoFrame.setFromPixels(vidGrabber.getPixelsRef());
        backsubsBlock.substract(videoFrame);
        backsubsBlock.update();
        resultFrame = backsubsBlock.getResult();
    }
}

//--------------------------------------------------------------
void testApp::draw()
{
    vidGrabber.draw(0,0);
    resultFrame.draw(camWidth, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    printf("\nKey Pressed: %c", key);

    switch (key)
    {

    case 's':
    case 'S':
        vidGrabber.videoSettings();
        break;
    case ' ':
        setNewBackground();
        break;
    case 'a':
    case 'A':
        addNewBackground();
        break;
    default:
        backsubsBlock.setMode(key);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}

void testApp::setNewBackground()
{
    videoFrame.setFromPixels(vidGrabber.getPixelsRef());
    backsubsBlock.setBackground(videoFrame);
}

void testApp::addNewBackground()
{
    videoFrame.setFromPixels(vidGrabber.getPixelsRef());
    backsubsBlock.addToBackground(videoFrame);
}
