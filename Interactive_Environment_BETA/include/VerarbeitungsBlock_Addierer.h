#ifndef VERARBEITUNGSBLOCK_ADDIERER_H
#define VERARBEITUNGSBLOCK_ADDIERER_H

#include "Block.h"

class VerarbeitungsBlock_Addierer : public Block
{
    public:
        VerarbeitungsBlock_Addierer();
        virtual ~VerarbeitungsBlock_Addierer();
    protected:

        bool verarbeiteWerte();

    private:

        Eingang eingang1;
        Eingang eingang2;
        Ausgang ausgang;
};

#endif // VERARBEITUNGSBLOCK_ADDIERER_H
