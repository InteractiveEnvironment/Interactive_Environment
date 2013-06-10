#pragma once
#include "Port.h"
#include <typeinfo>

template <typename T> struct PortImpl : Port
{
	/**
	 * Typ der Daten, die über den Port verfügbar sind.
	 */
    static const std::type_info& typ;
};

template <typename T>
const std::type_info& PortImpl<T>::typ = typeid(T);
