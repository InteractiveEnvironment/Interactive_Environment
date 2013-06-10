#pragma once
#include "AusgangImpl.h"
#include "Eingang.h"
#include <sstream>
#include <iostream>

template <typename T>
class EingangImpl : public PortImpl<T>, public Eingang
{
private:

    const AusgangImpl<T>* ausgang;
   	std::string _name;

public:

    EingangImpl(const std::string& name) : PortImpl<T>(), ausgang(nullptr)
    {
        _name = name;
    }

    virtual void verbinden(const AusgangImpl<T>& ausgang)
    {
        std::cout << "Verbinde Nummer 1 verwendet" << std::endl;
        this->ausgang = &ausgang;
    }

    virtual void verbinden(const Ausgang& ausgang)
    {
        std::cout << "Verbinde Nummer 2 verwendet" << std::endl;
        const AusgangImpl<T>* a = dynamic_cast<const AusgangImpl<T>* > (&ausgang);
        if(a!=nullptr)
        {
            this->ausgang = a;
        }
    }

    virtual void trennen()
    {
		ausgang = nullptr;
	}

	virtual bool istVerbunden() const
	{
		return ausgang!=nullptr;
	}


    /** Getter fuer Referenz auf Daten **/
	T* daten() const
    {
        if(ausgang!=nullptr)
        {
			return ausgang->daten();
		}
		else
		{
			return nullptr;
		}
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

		s << "Eingang " << name();
		if(ausgang!=nullptr)
		{
			s << " empfängt Daten des Typs " << PortImpl<T>::typ.name() << " von Ausgang " << ausgang->name();
		}
		else
		{
			s << "ist nicht verbunden und kann Daten des Typs " << PortImpl<T>::typ.name() << " empfangen";
		}

		return s.str();
	}
};
