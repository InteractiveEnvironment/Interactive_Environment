#ifndef EINGANGSBLOCK_ZUFALLSZAHL_H
#define EINGANGSBLOCK_ZUFALLSZAHL_H

#include "Block.h"

class EingangsBlock_Zufallszahl : public Block
{
    public:
        EingangsBlock_Zufallszahl();
        virtual ~EingangsBlock_Zufallszahl();
    protected:
        bool verarbeiteWerte();
    private:
        Ausgang ausgang;
};

#endif // EINGANGSBLOCK_ZUFALLSZAHL_H
