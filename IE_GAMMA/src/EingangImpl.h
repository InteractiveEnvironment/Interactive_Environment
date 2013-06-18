#pragma once
#include "Eingang.h"
#include "AusgangImpl.h"
#include <sstream>

template <typename T>
class EingangImpl : public PortImpl<T>, public Eingang
{
private:

    AusgangImpl<T>* ausgang;
   	std::string _name;

public:

    EingangImpl(const std::string& name) : PortImpl<T>(), ausgang(nullptr)
    {
		_name = name;
    }
    
	virtual bool istKompatibel(const Ausgang& ausgang) const
	{
        const AusgangImpl<T>* a = dynamic_cast<const AusgangImpl<T>* > (&ausgang);
        return (a!=nullptr);
	}

    virtual void verbinden(AusgangImpl<T>& ausgang)
    {
        this->ausgang = &ausgang;
        ausgang.verbinden(this);
    }

    virtual void verbinden(Ausgang& ausgang)
    {
        AusgangImpl<T>* a = dynamic_cast<AusgangImpl<T>* > (&ausgang);
        if(a!=nullptr)
        {
            this->ausgang = a;
            a->verbinden(this);
        }
    }

    virtual void trennen()
    {
        if(ausgang!=nullptr)
        {
            ausgang->trennen(this);
            ausgang = nullptr;
        }
	}

	virtual bool istVerbunden() const
	{
		return ausgang!=nullptr;
	}

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

	virtual std::string name() const
	{
		return _name;
	}

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
			s << " kann Daten des Typs " << PortImpl<T>::typ.name() << " empfangen";
		}

		return s.str();
	}
};
