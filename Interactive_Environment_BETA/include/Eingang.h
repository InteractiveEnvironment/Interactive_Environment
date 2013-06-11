#ifndef EINGANG_H
#define EINGANG_H

#include "Port.h"
#include "Ausgang.h"
#include "Eingang_Interface.h"

template <typename T>
class Eingang : public Port<T>, public Eingang_Interface
{
    public:
        Eingang();
        virtual ~Eingang();
        /** Weißt dem Eingang einen bestimmten Ausgang eines anderen Blockes zu
        @param Zu Verbindender Ausgang: Die Adresse des Ausgangs der mit dem Eingang verbunden werden soll **/
        bool verbinde(Ausgang<T> *); //Man könnte sogar den Eingang mit dem Ausgang des selben Blockes verbinden um Schleifen zu erzeugen...

        /** Gibt aktuell gespeicherten Wert zurück (Getter)
        @return aktuell gespeicherter Wert  **/
        T* gebeWert();

    protected:
    private:
        /** Aktuell gespeicherte Daten **/
        T wert;

        /** Aktuell verbundener Ausgang
            Wenn == NULL ist kein Ausgang verbunden **/
        Ausgang<T> * verbundenerAusgang; //Zeiger auf den Ausgang eines anderen Blockes

        /** Holt den Wert am verbundenem Ausgang ab und speichert ihn **/
        bool aktualisiereWert();
};

#endif // EINGANG_H
