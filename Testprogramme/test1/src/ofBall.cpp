#include "ofBall.h"

ofBall::ofBall(float _x,float _y, int _dim)
{

    x = _x;
    y = _y;

    speedX = ofRandom(-1,1);
    speedY = ofRandom(-1,1);

    dim = _dim;

}


//  Aufruf der update()-Methode in ofBall
void ofBall::update()
{

    if(x < 0 )
    {
        x = 0;
        speedX *= -1;
    }
    else if(x > ofGetWidth())
    {
        x = ofGetWidth();
        speedX *= -1;
    }

    if(y < 0 )
    {
        y = 0;
        speedY *= -1;
    }
    else if(y > ofGetHeight())
    {
        y = ofGetHeight();
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}



// Aufruf der draw()-Methode in ofBall
void ofBall::draw()
{
    ofSetColor(120,120,120);
    ofCircle(x, y, dim);

}
