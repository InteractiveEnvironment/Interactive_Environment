#pragma once
#include "Ausgang.h"
#include "PortImpl.h"
#include <sstream>

template <typename T>
class AusgangImpl : public PortImpl<T> , public Ausgang
{
private:

    T* _daten;
   	std::string _name;

public:

	AusgangImpl(const std::string& name) : PortImpl<T>()
	{
	    _name = name;
	}

	void setzeDaten(T* daten)
	{
		_daten = daten;
	}

    /** Getter fuer Referenz auf Daten **/
    T* daten() const
    {
        return _daten;
    }

    /** Getter fuer Name **/
	virtual std::string name() const
	{
		return _name;
	}

    /** Getter fuer Beschreibung **/
    std::string text() const
	{
		std::stringstream s;
		s << "Ausgang " << name() << " liefert Daten des Typs " << PortImpl<T>::typ.name();
		return s.str();
	}
};
