#include "Eingang.h"

Eingang::Eingang()
{
    //ctor
}

Eingang::~Eingang()
{
    //dtor
}

bool Eingang::verbinde(Ausgang * zuVerbindenderAusgang){
    // TODO: checken, ob Ausgang != NULL ist
    this->verbundenerAusgang = zuVerbindenderAusgang;
}

bool Eingang::holeWert(){
    // Wert von verbundenem Ausgang holen
}
float Eingang::gebeWert(){
    return this->wert;
}
