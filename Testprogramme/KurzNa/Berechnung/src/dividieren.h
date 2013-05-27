#ifndef DIVIDIEREN_H
#define DIVIDIEREN_H


class dividieren
{
    public:
        dividieren();
        virtual ~dividieren();
        float ergebnis;
        float getParameter(float p1, float p2);
    protected:
    private:
        float n1;
        float n2;
        float sol;
        float teilen(float zahl1, float zahl2);
};

#endif // DIVIDIEREN_H
