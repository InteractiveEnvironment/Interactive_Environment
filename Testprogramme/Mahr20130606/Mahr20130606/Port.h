#pragma once
#include <string>

struct Port
{
    virtual ~Port() {}

    /**
     * Liefert den Namen des Ports zurück.
     * @return Name des Ports
     */
	virtual std::string getName() const = 0;

	/**
	 * Liefert eine textuelle Beschreibung des Ports zurück.
	 * @return textuelle Beschreibung des Ports
	 */
    virtual std::string text() const = 0;
};
