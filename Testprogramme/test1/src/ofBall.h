#ifndef OFBALL_H_INCLUDED
#define OFBALL_H_INCLUDED
#include "ofMain.h"

class ofBall {

public:
        // Methoden

        void update();
        void draw();

        // Konstruktor

        ofBall(float x, float y, int dim);

        // Variablen

        float x;
        float y;
        int dim;
        float speedX;
        float speedY;

private:


};



#endif // OFBALL_H_INCLUDED
