#include "dividieren.h"
#include <iostream>

using namespace std;

dividieren::dividieren()
{
    //ctor
}

dividieren::~dividieren()
{
    //dtor
}


float dividieren::getParameter(float p1, float p2){
n1 = p1;
n2 = p2;

ergebnis = teilen(n1, n2);

return ergebnis;
}

float dividieren::teilen(float zahl1, float zahl2){

    sol = zahl1/zahl2;


return sol;
}
