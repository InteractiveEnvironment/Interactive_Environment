#ifndef AUSGANG_H
#define AUSGANG_H


class Ausgang
{
    public:
        Ausgang();
        virtual ~Ausgang();
        /** Gibt im Ausgang gespeicherten Wert / gespiechteres Wertobjekt zurück (Getter)
            @return wert **/
        float gebeWert();
        /** Aktualisiert den Wert, der im Ausgang gespeichert ist
        @param neuer Wert, der im Ausgang gespeichert werden soll **/
        bool aktualisiereWert(float);
    protected:
    private:
        float wert; //Kann durch Klasse ersetzt werden um erweiterbar zu machen
};

#endif // AUSGANG_H
