#ifndef AUSGANG_H
#define AUSGANG_H

#include <iostream>
#include "Port.h"
#include "Ausgang_Interface.h"

template <typename T>
class Ausgang : public Port<T>, public Ausgang_Interface
{
    public:
        Ausgang();
        virtual ~Ausgang();
        /** Gibt im Ausgang gespeicherten Wert / gespiechteres Wertobjekt zurück (Getter)
            @return Referenz auf den aktuellen Wert **/
        T* gebeWert();

        /** Aktualisiert den Wert, der im Ausgang gespeichert ist
        @param neuer Wert, der im Ausgang gespeichert werden soll **/
        bool aktualisiereWert(T*);
    protected:
    private:
        T wert; //Kann durch Klasse ersetzt werden um erweiterbar zu machen
};

#endif // AUSGANG_H
