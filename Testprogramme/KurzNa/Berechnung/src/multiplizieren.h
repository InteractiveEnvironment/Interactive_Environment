#ifndef MULTIPLIZIEREN_H
#define MULTIPLIZIEREN_H


class multiplizieren
{
    public:
        multiplizieren();
        virtual ~multiplizieren();
        float ergebnis;
        float getParameter(float p1, float p2);

    protected:
    private:
        float n1;
        float n2;
        float sol;
        float mahlnehmen(float zahl1, float zahl2);
};

#endif // MULTIPLIZIEREN_H
