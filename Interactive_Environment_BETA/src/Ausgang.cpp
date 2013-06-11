#include "Ausgang.h"

Ausgang::Ausgang()
{
    //ctor
    std::cout << "Template Dings: " << T << std::endl;
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
