#ifndef EINGANGSBLOCK_HOCHZAEHLER_H
#define EINGANGSBLOCK_HOCHZAEHLER_H

#include "Block.h"

class EingangsBlock_Hochzaehler : public Block
{
    public:
        EingangsBlock_Hochzaehler();
        virtual ~EingangsBlock_Hochzaehler();
    protected:
        bool verarbeiteWerte();
    private:
        Ausgang ausgang;
};

#endif // EINGANGSBLOCK_HOCHZAEHLER_H
