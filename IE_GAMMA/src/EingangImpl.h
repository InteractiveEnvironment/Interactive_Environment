#pragma once
#include "Eingang.h"
#include "AusgangImpl.h"
#include <sstream>

/**
 * Jeder konkrete Eingang kann nur genau einen Datentyp empfangen.
 * @tparam Datentyp, welcher vom Eingang empfangen werden kann.
 */
template <typename T>
class EingangImpl : public PortImpl<T>, public Eingang
{
private:
    /**
     * Jeder Eingang kennt einen Ausgang, mit welchem er verbunden ist.
     * Gibt es keine Verbindung, ist der Ausgang ein Nullpointer.
     */
    AusgangImpl<T>* ausgang;

    /** Name des Eingangs */
   	std::string _name;

public:

    EingangImpl(const std::string& name) : PortImpl<T>()
    {
		_name = name;
		ausgang = nullptr;
    }

    //TODO: Destructor

    /**
     * Überprüft, ob ein Ausgang mit diesem Eingang kompatibel ist, also den gleichen Datentyp bereitstellt
     * @param Ausgang
     * @return true, wenn kompatibel
     */
	virtual bool istKompatibel(const Ausgang& ausgang) const
	{
	    // dynamic_cast gibt nullptr zurück, wenn sich Objekt nicht casten lässt
        const AusgangImpl<T>* a = dynamic_cast<const AusgangImpl<T>* > (&ausgang);
        return (a!=nullptr);
	}

    /**
     * Speichert den Ausgang um später dessen Daten zu holen
     * Ruft verbinden() in diesem Ausgang auf
     * Diese Funktion wird aufgerufen, wenn der Ausgang mit diesem Eingang kompatibel ist
     * @param AusgangImpl, der mit diesem Eingang verbunden werden soll
     *
     */
    virtual void verbinden(AusgangImpl<T>& _ausgang)
    {
        this->ausgang = &_ausgang;
        _ausgang.verbinden(this);
    }

    /**
     * Speichert den Ausgang um später dessen Daten zu holen
     * Ruft verbinden() in diesem Ausgang auf
     * Diese Funktion wird aufgerufen, wenn unklar ist, ob der Ausgang mit diesem Eingang kompatibel ist
     * @param Ausgang, der mit diesem Eingang verbunden werden soll
     */
    virtual void verbinden(Ausgang& _ausgang)
    {
        //TODO: Überprüfung durch istKompatibel() ersetzen!
        AusgangImpl<T>* a = dynamic_cast<AusgangImpl<T>* > (&_ausgang);
        if(a!=nullptr)
        {
            //TODO: Folgenden Code durch verbinden() ersetzen
            this->ausgang = a;
            a->verbinden(this);
        }
    }

    /**
     * Ruft beim Ausgang trennen() auf
     * Setzt den verbundenen Ausgang auf einen Nullpointer
     */
    virtual void trennen()
    {
        if(ausgang!=nullptr)
        {
            ausgang->trennen(this);
            ausgang = nullptr;
        }
	}
    /**
     * Überprüft, ob dieser Eingang bereits mit einem Ausgang verbunden ist
     * @return true, wenn eine Verbindung besteht
     */
	virtual bool istVerbunden() const
	{
		return ausgang!=nullptr;
	}

    /**
     * Der Eingang holt die Daten aus dem verbundenem Ausgang ab und stellt sie selbst bereit
     * @return Zeiger auf die Daten im verbundenem Ausgang, wenn nicht verbunden dann Nullpointer
     */
	T* daten() const
    {
        if(ausgang!=nullptr)
        {
			return ausgang->daten();
		}
		else
		{
		    //std::cout << "Ausgang ist nullpointer" << std::endl;
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
