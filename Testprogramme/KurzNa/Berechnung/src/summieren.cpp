#include "summieren.h"

summieren::summieren()
{
    //ctor
}

summieren::~summieren()
{
    //dtor
}

float summieren::getParameter(float p1, float p2){
n1 = p1;
n2 = p2;

ergebnis = zusammenzaehlen(n1, n2);

return ergebnis;
}

float summieren::zusammenzaehlen(float zahl1, float zahl2){

    sol = zahl1+zahl2;


return sol;
}
