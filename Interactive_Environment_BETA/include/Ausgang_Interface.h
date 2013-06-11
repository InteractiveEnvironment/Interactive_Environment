#ifndef AUSGANG_INTERFACE_H
#define AUSGANG_INTERFACE_H

#include "Port_Interface.h"

class Ausgang_Interface : public Port_Interface
{
    public:
        Ausgang_Interface() {}
        virtual ~Ausgang_Interface() {}

        virtual T* gebeWert() = 0;
        virtual bool aktualisiereWert(T*) = 0;

    protected:
    private:
};

#endif // AUSGANG_INTERFACE_H
