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

   int radius;
   int centreX, centreY;
   int nRings;
   int marginX, marginY;
   vector <ieRing*> rings;
    vector <ieRing*>::iterator  itRings;

};



#endif // IEPATCH_H_INCLUDED
