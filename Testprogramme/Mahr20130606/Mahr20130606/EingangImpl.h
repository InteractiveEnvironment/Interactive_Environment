#pragma once
#include "AusgangImpl.h"
#include "Eingang.h"
#include <sstream>

template <typename T>
class EingangImpl : public PortImpl<T>, public Eingang
{
private:

    const AusgangImpl<T>* ausgang;
   	std::string _name;

public:

    EingangImpl(const std::string& name) : PortImpl<T>(), ausgang(nullptr)
    {
    }

    virtual void verbinden(const AusgangImpl<T>& ausgang)
    {
        this->ausgang = &ausgang;
    }

    virtual void verbinden(const Ausgang& ausgang)
    {
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
