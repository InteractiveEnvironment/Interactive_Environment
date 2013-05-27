#include "subtrahieren.h"

subtrahieren::subtrahieren()
{
    //ctor
}

subtrahieren::~subtrahieren()
{
    //dtor
}

float subtrahieren::getParameter(float p1, float p2){
n1 = p1;
n2 = p2;

ergebnis = abziehen(n1, n2);

return ergebnis;
}

float subtrahieren::abziehen(float zahl1, float zahl2){

    sol = zahl1-zahl2;
return sol;
}
