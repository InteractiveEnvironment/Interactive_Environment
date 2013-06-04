#include "EingangsBlock_Hochzaehler.h"

EingangsBlock_Hochzaehler::EingangsBlock_Hochzaehler()
{
    ausgaenge.push_back(&ausgang);
}

EingangsBlock_Hochzaehler::~EingangsBlock_Hochzaehler()
{
    //dtor
}

bool EingangsBlock_Hochzaehler::verarbeiteWerte(){
    generierterWert++;
}
