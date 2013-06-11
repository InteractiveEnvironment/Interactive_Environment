#include "Port.h"

Port::Port()
{
    //ctor
    this->typ = typeid(T); //typeid gibt den Datentyp zurück
}

Port::~Port()
{
    //dtor
}
