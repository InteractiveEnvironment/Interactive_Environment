#ifndef IEPATCH_H_INCLUDED
#define IEPATCH_H_INCLUDED
#include "ofMain.h"
#include "ieRing.h"
#define MARGIN_X 20
#define MARGIN_Y 20

class iePatch
{
public:
    iePatch(int defaultRings=3);
    void addRing();
    void draw();
    void removeRing();

private:
    int radius;  // Radius des anzuzeigenden Kreises
    int centreX, centreY;  // Mittelpunkt des anzuzeigenden Kreises
    int marginX, marginY;  // Margin-Werte für horizontalen und vertikalen Abstand on Fensterrand zu äußerster Kreislinie
    vector <ieRing*> rings;  // Vektor als Container für alle Ringe
    vector <ieRing*>::iterator  itRings;  // Iterator für Vektor aller Ringe
    void reCalcRings();
};



#endif // IEPATCH_H_INCLUDED
