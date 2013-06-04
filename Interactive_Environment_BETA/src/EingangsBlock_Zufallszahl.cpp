#include "EingangsBlock_Zufallszahl.h"

EingangsBlock_Zufallszahl::EingangsBlock_Zufallszahl()
{
    ausgaenge.push_back(&ausgang);
}

EingangsBlock_Zufallszahl::~EingangsBlock_Zufallszahl()
{
    //dtor
}

bool EingangsBlock_Zufallszahl::verarbeiteWerte(){
    generierterWert = ofRandom(2);
}
