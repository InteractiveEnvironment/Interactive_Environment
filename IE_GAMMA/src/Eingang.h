#pragma once
#include "Port.h"
class Ausgang; //Funktioniert, ist ein workaround

/**
 * Interface für die EingangsImpl-Klasse
 */
struct Eingang : Port
{
	/**
	 * Prüft ob der Eingang mit einem bestimmten Ausgang verbunden werden kann.
	 * @param ausgang Ausgang
	 * @return true, falls der Eingang mit dem Ausgang verbunden werden kann.
	 */
	virtual bool istKompatibel(const Ausgang& ausgang) const = 0;

	/**
	 * Verbindet den Eingang mit einem Ausgang.
	 * @param ausgang Ausgang
	 */
	virtual void verbinden(Ausgang& ausgang) = 0;

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
