#include "EingangsBlock_Zufallszahl.h"

EingangsBlock_Zufallszahl::EingangsBlock_Zufallszahl()
{
    ausgaenge.push_back(&ausgang);
    generierterWert = 0;
}

EingangsBlock_Zufallszahl::~EingangsBlock_Zufallszahl()
{
    //dtor
}

bool EingangsBlock_Zufallszahl::verarbeiteWerte(){
    generierterWert++;
}
