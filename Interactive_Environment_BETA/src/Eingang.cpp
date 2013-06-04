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

bool Eingang::aktualisiereWert(){
    // Wert von verbundenem Ausgang holen
    this->wert = this->verbundenerAusgang->gebeWert();
}
float Eingang::gebeWert(){
    this->aktualisiereWert();
    return this->wert;
}
