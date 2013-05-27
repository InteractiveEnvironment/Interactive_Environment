#ifndef SUBTRAHIEREN_H
#define SUBTRAHIEREN_H


class subtrahieren
{
    public:
        subtrahieren();
        virtual ~subtrahieren();
        float ergebnis;
        float getParameter(float p1, float p2);
    protected:
    private:
        float n1;
        float n2;
        float sol;
        float abziehen(float zahl1, float zahl2);
};

#endif // SUBTRAHIEREN_H
