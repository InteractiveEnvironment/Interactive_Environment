#pragma once
#include <string>

/**
 * Interface für Ports
 * Es stellt bisher keine für den Programmablauf notwendigen Funktionen bereit.
 */
struct Port
{
    virtual ~Port() {}

    /**
     * Liefert den Namen des Ports zurück.
     * @return Name des Ports
     */
	virtual std::string name() const = 0;

	/**
	 * Liefert eine textuelle Beschreibung des Ports zurück.
	 * @return textuelle Beschreibung des Ports
	 */
    virtual std::string text() const = 0;
};
