#include "ieRing.h"

ieRing::ieRing(/*int radiusOut,*/ int centreX, int centreY/*,int color*/)
{


    //this->radiusIn = radiusOut-PADDING;
      this->radiusIn = 0;
      this->radiusOut = 0;
    //this->radiusOut = radiusOut;
    this->centreX = centreX;
    this->centreY = centreY;
    //this->color.set(50, color, 100);  // Definition des Farbverlaufs
    this->color.set(255,255,255);
}

void ieRing::draw()
{
    ofSetColor(230, 230, 230);  // Farbdefinition der Ringzwischenraum
    ofCircle(centreX, centreY, radiusOut);
    ofSetColor(color);
    ofCircle(centreX, centreY, radiusIn);
}


void ieRing::setRadius(int radius)
{

    this->radiusIn = radius-PADDING;
    this->radiusOut = radius;

}

void ieRing::setColor(int r,int g,int b)
{
    this->color.set(r,g,b);
}
