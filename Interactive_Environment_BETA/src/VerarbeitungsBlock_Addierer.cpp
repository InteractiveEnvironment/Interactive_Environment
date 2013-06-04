#include "VerarbeitungsBlock_Addierer.h"

VerarbeitungsBlock_Addierer::VerarbeitungsBlock_Addierer()
{
    eingaenge.push_back(&eingang1);
    eingaenge.push_back(&eingang2);
    ausgaenge.push_back(&ausgang);
}

VerarbeitungsBlock_Addierer::~VerarbeitungsBlock_Addierer()
{
    //dtor
}
bool VerarbeitungsBlock_Addierer::verarbeiteWerte(){
    generierterWert = eingaenge[0]->gebeWert() + eingaenge[1]->gebeWert();
}
