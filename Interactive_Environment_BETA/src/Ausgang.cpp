#include "Ausgang.h"

Ausgang::Ausgang()
{
    //ctor
}

Ausgang::~Ausgang()
{
    //dtor
}

float Ausgang::gebeWert(){
    return wert;
}
bool Ausgang::aktualisiereWert(float neuerWert){
    this->wert = neuerWert;
}
