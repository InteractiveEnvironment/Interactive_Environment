#ifndef EINGANG_H
#define EINGANG_H

#include "Ausgang.h"

class Eingang
{
    public:
        Eingang();
        virtual ~Eingang();
        /** Weißt dem Eingang einen bestimmten Ausgang eines anderen Blockes zu
        @param Zu Verbindender Ausgang: Die Adresse des Ausgangs der mit dem Eingang verbunden werden soll **/
        bool verbinde(Ausgang *); //Man könnte sogar den Eingang mit dem Ausgang des selben Blockes verbinden um Schleifen zu erzeugen...

        /** Gibt aktuell gespeicherten Wert zurück (Getter)
        @return aktuell gespeicherter Wert  **/
        float gebeWert();

        /** Holt den Wert am verbundenem Ausgang ab und speichert ihn **/
        bool holeWert();

    protected:
    private:
        /** Aktuell gespeicherte Daten **/
        float wert;

        /** Aktuell verbundener Ausgang
            Wenn == NULL ist kein Ausgang verbunden **/
        Ausgang * verbundenerAusgang; //Zeiger auf den Ausgang eines anderen Blockes
};

#endif // EINGANG_H
