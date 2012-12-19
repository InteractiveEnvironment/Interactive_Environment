#include "ieRing.h"

ieRing::ieRing(int radiusOut, int centreX, int centreY,int color)
{

    this->radiusIn = radiusOut-PADDING;
    this->radiusOut = radiusOut;
    this->centreX = centreX;
    this->centreY = centreY;
    this->color.set(color,50,50);




}

void ieRing::draw()
{
    ofSetColor(50,50,50);
    ofCircle(centreX,centreY,radiusOut);
    ofSetColor(color);
    ofCircle(centreX,centreY,radiusIn);

}
