#pragma once
#include "Ausgang.h"
#include "Eingang.h"
#include "PortImpl.h"
#include <algorithm>
#include <sstream>
#include <vector>

template <typename T>
class AusgangImpl : public PortImpl<T> , public Ausgang
{
private:

    T* _daten;
   	std::string _name;

   	std::vector<Eingang*> eingaenge;

public:

	AusgangImpl(const std::string& name) : PortImpl<T>()
	{
		_name = name;
	}

	virtual ~AusgangImpl()
	{
	    for(Eingang* e : eingaenge)
	    {
	        e->trennen();
	    }
	}

	void setzeDaten(T* daten)
	{
		_daten = daten;
	}

    T* daten() const
    {
        return _daten;
    }

	virtual std::string name() const
	{
		return _name;
	}

	virtual void trennen(Eingang* e)
	{
	    std::vector<Eingang*>::iterator it = std::find(eingaenge.begin(), eingaenge.end(), e);
	    if (it != eingaenge.end())
	    {
            eingaenge.erase(it);
	    }
	}

	virtual void verbinden(Eingang* e)
	{
	    eingaenge.push_back(e);
	}

    std::string text() const
	{
		std::stringstream s;
		s << "Ausgang " << name() << " liefert Daten des Typs " << PortImpl<T>::typ.name();
		return s.str();
	}
};
