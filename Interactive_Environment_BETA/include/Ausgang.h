#ifndef AUSGANG_H
#define AUSGANG_H


class Ausgang
{
    public:
        Ausgang();
        virtual ~Ausgang();
        /** Gibt im Ausgang gespeicherten Wert / gespiechteres Wertobjekt zurück (Getter)
            @return wert
        **/
        float liefereWert();
    protected:
    private:
        float wert; //Kann durch Klasse ersetzt werden um erweiterbar zu machen
};

#endif // AUSGANG_H
