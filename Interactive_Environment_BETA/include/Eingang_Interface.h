#ifndef EINGANG_INTERFACE_H
#define EINGANG_INTERFACE_H

#include "Port_Interface.h"

class Eingang_Interface : public Port_Interface
{
    public:
        Eingang_Interface() {}
        virtual ~Eingang_Interface() {}

        virtual bool verbinde(Ausgang<T> *) = 0;

        virtual T* gebeWert() = 0;

    protected:
    private:
};

#endif // EINGANG_INTERFACE_H
