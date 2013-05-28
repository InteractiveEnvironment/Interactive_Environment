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
    protected:
        /** Liste aller Ausgänge **/
        std::vector<Ausgang *> ausgaenge;
        /** Liste aller Eingänge **/
        std::vector<Eingang *> eingaenge;
    private:
        /** Iteriert über die Eingangsliste um aktuelle Werte zu holen
            Die Werte werden im zugehörigem Eingangsobjekt gespiechert **/
        bool holeWerte();
        /** Generiert einen neuen Wert aus den vorhandenen Werten in den Eingängen **/
        bool verarbeiteWerte();
        /** Speichert den generierten Wert im Ausgang **/
        bool aktualisiereAusgang();
};

#endif // BLOCK_H
