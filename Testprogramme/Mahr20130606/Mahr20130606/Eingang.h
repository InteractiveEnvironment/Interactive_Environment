#pragma once
#include "Port.h"
class Ausgang;

struct Eingang : Port
{
	/**
	 * Verbindet den Eingang mit einem Ausgang.
	 * @param ausgang Ausgang
	 */
	virtual void verbinden(const Ausgang& ausgang) = 0;
	
	/**
	 * Trennt den Eingang vom Ausgang.
	 */
	virtual void trennen() = 0;
	
	/**
	 * Liefert true zurück, falls der Eingang mit einem Ausgang verbunden ist.
	 * @return true, falls der Eingang mit einem Ausgang verbunden ist
	 */
	virtual bool istVerbunden() const = 0;
};
