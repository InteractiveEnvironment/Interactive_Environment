#ifndef VERBINDUNG_H
#define VERBINDUNG_H


class verbindung
{
    public:
        verbindung();
        virtual ~verbindung();
    protected:
    private:
        /** blockA, blockB: Die Blöcke, die miteinander verbunden werden **/
        Block blockA;
        Block blockB;
};

#endif // VERBINDUNG_H
