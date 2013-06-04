#include "AusgabeBlock_Konsole.h"

AusgabeBlock_Konsole::AusgabeBlock_Konsole()
{
    eingaenge.push_back(&eingang);
    generierterWert = 0;
}

AusgabeBlock_Konsole::~AusgabeBlock_Konsole()
{
    //dtor
}
 bool AusgabeBlock_Konsole::verarbeiteWerte(){
    generierterWert = eingaenge[0]->gebeWert();
    std::cout << generierterWert << std::endl;
}
