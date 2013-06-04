#ifndef BLOCK_H
#define BLOCK_H

#include "Ausgang.h"
#include "Eingang.h"
#include <vector>

class Block
{
    public:
        Block();
        virtual ~Block();
        /** Führt alle notwendigen Funktionen aus um einen aktualisierten Ausgang bereitzustellen **/
        bool update();

        /** Getter für Eingänge eines Blockes
            @return Liefert einen Zeiger auf den angeforderten Eingang zurück
            @param Die Nummer des Eingangs >=0 **/
        Eingang * gebeEingang(unsigned int);

        /** Getter für Ausgänge eines Blockes
            @return Liefert einen Zeiger auf den angeforderten Ausgang zurück
            @param Die Nummer des Ausgangs >=0 **/
        Ausgang * gebeAusgang(unsigned int);

    protected:
        /** Liste aller Ausgänge **/
        std::vector<Ausgang *> ausgaenge;

        /** Liste aller Eingänge **/
        std::vector<Eingang *> eingaenge;

        /** Temporär gespeicherte, generierte Wert **/
        float generierterWert;

//        /** Iteriert über die Eingangsliste um aktuelle Werte zu holen
//            Die Werte werden im zugehörigem Eingangsobjekt gespiechert
//            @return true wenn alle Werte erfolgreich aktualisiert wurden, false wenn mindestens ein Versuch fehlgeschlagen ist **/
//        bool holeWerte();

        /** Generiert einen neuen Wert aus den vorhandenen Werten in den Eingängen **/
        virtual bool verarbeiteWerte() = 0; // Virtual, da abstrakt, da von jedem Block anders implementiert

        /** Speichert den generierten Wert im Ausgang **/
        bool aktualisiereAusgang();

    private:

};

#endif // BLOCK_H
