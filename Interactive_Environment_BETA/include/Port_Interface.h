#ifndef PORT_INTERFACE_H
#define PORT_INTERFACE_H

#include <string>

class Port_Interface
{
    public:
        Port_Interface() {}
        virtual ~Port_Interface() {}

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


    protected:
    private:
};

#endif // PORT_INTERFACE_H
