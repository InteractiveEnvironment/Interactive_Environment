#ifndef AUSGABEBLOCK_KONSOLE_H
#define AUSGABEBLOCK_KONSOLE_H

#include <iostream>
#include "Block.h"

class AusgabeBlock_Konsole : public Block
{
    public:
        AusgabeBlock_Konsole();
        virtual ~AusgabeBlock_Konsole();
    protected:
        bool verarbeiteWerte();

    private:
        Eingang eingang;
};

#endif // AUSGABEBLOCK_KONSOLE_H
