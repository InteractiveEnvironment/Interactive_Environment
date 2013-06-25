#pragma once
#include "Port.h"
#include <typeinfo>

/**
 * Die Klasse PortImpl stellt die Elternklasse für die Klassen Eingang und Ausgang dar
 * @tparam Datentyp, welcher vom Port empfangen bzw. bereitgestellt wird
 */
template <typename T>
struct PortImpl : Port
{
	/**
	 * Datentyp, welcher vom Port empfangen bzw. bereitgestellt wird
	 */
    static const std::type_info& typ;
};

// wird für jeden verwendeten Datentyp genau einmal ausgeführt
template <typename T>
const std::type_info& PortImpl<T>::typ = typeid(T);
