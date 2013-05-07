#include "ieRing.h"

ieRing::ieRing(int radiusOut, int centreX, int centreY,int color)
{
    this->radiusIn = radiusOut-PADDING;
    this->radiusOut = radiusOut;
    this->centreX = centreX;
    this->centreY = centreY;
    this->color.set(50, color, 100);  // Definition des Farbverlaufs
}

void ieRing::draw()
{
    ofSetColor(230, 230, 230);  // Farbdefinition der Ringzwischenraum
    ofCircle(centreX, centreY, radiusOut);
    ofSetColor(color);
    ofCircle(centreX, centreY, radiusIn);
}
