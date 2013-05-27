#include "multiplizieren.h"

multiplizieren::multiplizieren()
{
    n1 = 0.00;
    n2 = 0.00;
}

multiplizieren::~multiplizieren()
{
    //dtor
}

float multiplizieren::getParameter(float p1, float p2){
n1 = p1;
n2 = p2;

ergebnis = mahlnehmen(n1, n2);

return ergebnis;
}

float multiplizieren::mahlnehmen(float zahl1, float zahl2){

sol = zahl1 * zahl2;
return sol;
}
