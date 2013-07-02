#pragma once
#include <vector>
#include "Ausgang.h"
#include "Eingang.h"

/**
 * Interface für konkrete Blockklassen
 */
class Block
{
private:
    /** Bezeichnung des Blockes */
	string _name;
	/** Liste der verfügbaren Eingänge des Blockes */
	vector<Eingang*> eingang;
	/** Liste der verfügbaren Ausgänge des Blockes */
	vector<Ausgang*> ausgang;

protected:

    /**
     * Schreibt einen Eingang in die Liste der Eingänge
     * @param zu speichernder Eingang
     */
	void eingangHinzufuegen(Eingang* e)
	{
		eingang.push_back(e);
	}

    /**
     * Schreibt einen Ausgang in die Liste der Ausgänge
     * @param zu speichernder Ausgang
     */
	void ausgangHinzufuegen(Ausgang* a)
	{
		ausgang.push_back(a);
	}

public:

	Block(const string& name)
	{
	    _name = name;
	}

	virtual ~Block()
	{
	    // Iteriert über alle Einträge im Vektor Eingang
		for(Eingang* e : eingang)
		{
			delete e;
			std::cout << this->name() << " hat Eingang " << e->name() << " getrennt" <<std::endl;
		}

        //Iteriert über alle Einträge im Vektor Ausgang
		for(Ausgang* a : ausgang)
		{
		    // Ruft den Destruktor, und damit trennen() im Ausgang auf
			delete a;
            std::cout << this->name() << " hat Ausgang " << a->name() << " getrennt" << std::endl;
		}

		std::cout << "Block " << this->name() << " wird gelöscht" << std::endl;
	}

    /**
     * Standardfunktion, welche jeder Block implementieren muss.
     * update() sollte in der openFrameworks testApp::update() aufgerufen werden
     * Es dürfen hier keine draw-Operationen durchgeführt werden
     * (Kann auch leer implementiert werden)
     */
	virtual void update() = 0;

    /**
     * Standardfunktion, welche jeder Block implementieren muss.
     * draw() sollte in der openFrameworks testApp::draw() aufgerufen werden
     * Es dürfen hier keine Werteberechnungen durchgeführt werden
     * (Kann auch leer implementiert werden)
     */
	virtual void draw() = 0;

    /**
     * Standardfunktion, welche jeder Block implementieren muss.
     * trigger() sollte von openFrameworks Events aufgerufen werden
     * Es dürfen hier keine draw-Operationen durchgeführt werden
     * (Kann auch leer implementiert werden)
     * @param keycode
     */
	virtual void trigger(int key = 0) = 0;

    /**
     * Getter für den Vektor, in welchem alle verfügbaren Eingänge gespeichert sind
     * @return Vektor mit Eingängen des Blockes
     */
	const vector<Eingang*> eingaenge() const
	{
		return eingang;
	}

    /**
     * Getter für den Vektor, in welchem alle verfügbaren Ausgänge gespeichert sind
     * @return Vektor mit Ausgängen des Blockes
     */
	const vector<Ausgang*> ausgaenge() const
	{
		return ausgang;
	}

    /**
     * @return Bezeichnung des Blockes
     */
	virtual std::string name() const
	{
		return _name;
	}

    /**
     * @return Textuelle Beschreibung des Blockes
     */
	std::string text() const
	{
		std::stringstream s;

		s << "Block " << name() << "\nEingaenge:\n";
		for(Eingang* e : eingang)
		{
			s << e->text() << endl;
		}
		s << "Ausgänge:\n";
		for(Ausgang* a : ausgang)
		{
			s << a->text() << endl;
		}

		return s.str();
	}

	/**
	 * Verbindet einen Eingang dieses Blockes mit einem Ausgang eines Blockes
	 * @param eingangsIndex Index des Eingangs in der Liste der Eingänge des Blockes (enum) //TODO: besser bezeichnen!
	 * @param block Der Pointer auf den Block mit dessen Ausgang verbunden wird
	 * @param ausgangsIndex Index des Ausgang in der Liste der Ausgänge des Blockes, mit dem verbunden wird //TODO: besser bezeichnen!
	 */
    void verbinde (int eingangsIndex, Block *block, int ausgangsIndex)
    {
        std::cout << this->name() << " verbindet Eingang " << this->eingaenge()[eingangsIndex]->name() << " mit Ausgang " << block->ausgaenge()[ausgangsIndex]->name() << " von Block " << block->name() << std::endl;
        this->eingaenge()[eingangsIndex]->verbinden(*block->ausgaenge()[ausgangsIndex]);

    }


};
