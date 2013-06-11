#pragma once
#include "Port.h"
#include <typeinfo>

template <typename T>
struct PortImpl : Port
{
	/**
	 * Typ der Daten, die über den Port verfügbar sind.
	 */
    static const std::type_info& typ;
};

// Ausgelagerter Konstruktor
// Setzt die Variable typ von PortImpl<T> auf den RÜckgabewert von typeid
template <typename T>
const std::type_info& PortImpl<T>::typ = typeid(T); //typeid gibt den Datentyp zurück
