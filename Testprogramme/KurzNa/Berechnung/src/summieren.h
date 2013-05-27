#ifndef SUMMIEREN_H
#define SUMMIEREN_H


class summieren
{
    public:
        summieren();
        virtual ~summieren();
         float ergebnis;
        float getParameter(float p1, float p2);

    protected:
    private:
        float n1;
        float n2;
        float sol;
        float zusammenzaehlen(float zahl1, float zahl2);
};

#endif // SUMMIEREN_H
