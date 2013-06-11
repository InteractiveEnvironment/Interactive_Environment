#pragma once
#include "Ausgang.h"
#include "PortImpl.h"
#include <sstream>

template <typename T>
class AusgangImpl : public PortImpl<T> , public Ausgang
{
private:

    T daten;
    T* datenPointer;
   	std::string name;

public:

	AusgangImpl(const std::string& _name) : PortImpl<T>() //Konstruktor und Elternkonstruktor
	{
	    name = _name;
	}

    /** Setter fuer Datenobjekt
      * @param Referenz auf neue Daten
      */
	void setzeDaten(T* _daten)
	{
		daten = *_daten;
		datenPointer = &daten;
	}

    /** Getter fuer Referenz auf Daten
      * @return Referenz auf eigenes Datenobjekt
      */
    T* getDaten() const
    {
        return datenPointer;
    }

    /** Getter fuer Name **/
	virtual std::string getName() const
	{
		return name;
	}

    /** Getter fuer Beschreibung **/
    std::string text() const
	{
		std::stringstream s;
		s << "Ausgang " << getName() << " liefert Daten des Typs " << PortImpl<T>::typ.name();
		return s.str();
	}
};
