#include "iePatch.h"

iePatch::iePatch(int nRings)
{
    int tempSize;
    if(ofGetWidth()>ofGetHeight())
    {
        tempSize = ofGetHeight();
    }
    else
    {
        tempSize = ofGetWidth();
    }


    marginX = tempSize/MARGIN_X;
    marginY = tempSize/MARGIN_Y;

    if(marginX>marginY)
    {
        radius=0.5*tempSize-marginY;
    }
    else
    {
        radius=0.5*tempSize-marginX;
    }

    centreX = .5*tempSize;
    centreY = .5*tempSize;

    for(int i=0; i<nRings; i++)
    {

        rings.push_back(new ieRing(radius-((radius/nRings)*(i)),centreX,centreY,255-((255/nRings)*i)));
    }
}

void iePatch::draw()
{
    ofSetColor(255,50,50);
    ofCircle(centreX,centreY,radius);
    for(itRings=rings.begin(); itRings!=rings.end(); ++itRings)
    {
        (*itRings)->draw();
    }
       // rings[1]->draw();

}
