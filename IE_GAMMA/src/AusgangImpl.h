#pragma once
#include "Ausgang.h"
//#include "Eingang.h"
#include "PortImpl.h"
#include <algorithm>
#include <sstream>
#include <vector>

/**
 * Jeder konkrete Ausgang kann nur genau einen Datentyp bereitstellen.
 * @tparam Datentyp, welcher vom Ausgang bereitgestellt wird.
 */
template <typename T>
class AusgangImpl : public PortImpl<T> , public Ausgang
{
private:

    /**
     * Daten, welche im Ausgang zur Abholung bereit stehen.
     */
    T* _daten;

    /**
     * Liste aller Eingänge, welche mit diesem Ausgang verbunden sind.
     * Wichtig, falls Ausgang gelöscht wird, um vorher Verbindungen trennen zu können.
     */
   	std::vector<Eingang*> eingaenge;

    std::string _name;

public:

	AusgangImpl(const std::string& name) : PortImpl<T>()
	{
		_name = name;
	}

    /**
     * Wenn Ausgang gelöscht wird, wird an jedem verbundenem Eingang trennen() aufgerufen
     */
	virtual ~AusgangImpl()
	{
	    // Iteriert über jeden im Eingangsvektor gespeicherten Eintrag
	    for(Eingang* e : eingaenge)
	    {
	        e->trennen();
	    }
	}

    /**
     * Speichert die Adresse der bereitzustellenden Daten
     */
	void setzeDaten(T* daten)
	{
		_daten = daten;
	}

    /**
     * Gibt einen Pointer auf die bereitsgestellten Daten zurück
     * @return Pointer auf Daten
     */
    T* daten() const
    {
        return _daten;
    }

    /**
     * Speichert einen Eingang im Vektor
     * @param Zu speichernder Eingang
     */
	virtual void verbinden(Eingang* e)
	{
	    eingaenge.push_back(e);
	}

	/**
	 * Löscht einen Eingang aus dem Vektor
	 * @param zu löschender Eingang
	 */
	virtual void trennen(Eingang* e)
	{
	    std::vector<Eingang*>::iterator it = std::find(eingaenge.begin(), eingaenge.end(), e);
	    if (it != eingaenge.end())
	    {
            eingaenge.erase(it);
	    }
	}

    virtual std::string name() const
	{
		return _name;
	}

    std::string text() const
	{
		std::stringstream s;
		s << "Ausgang " << name() << " liefert Daten des Typs " << PortImpl<T>::typ.name();
		return s.str();
	}
};
