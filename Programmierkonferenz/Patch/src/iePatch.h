#ifndef IEPATCH_H_INCLUDED
#define IEPATCH_H_INCLUDED
#include "ofMain.h"
#include "ieRing.h"
#define MARGIN_X 20
#define MARGIN_Y 20

class iePatch
{
public:
    iePatch(int nRings=10);
    void draw();

private:
    int radius;  // Radius des anzuzeigenden Kreises
    int centreX, centreY;  // Mittelpunkt des anzuzeigenden Kreises
    int nRings;  // Anzahl der benoetigten Ringe
    int marginX, marginY;  // Margin-Werte für horizontalen und vertikalen Abstand on Fensterrand zu äußerster Kreislinie
    vector <ieRing*> rings;  // Vektor als Container für alle Ringe
    vector <ieRing*>::iterator  itRings;  // Iterator für Vektor aller Ringe
};



#endif // IEPATCH_H_INCLUDED
