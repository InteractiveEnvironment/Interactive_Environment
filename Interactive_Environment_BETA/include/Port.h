//#pragma once
#ifndef PORT_H
#define PORT_H

#include <typeinfo>
#include"Port_Interface.h"

template <typename T>
class Port : public Port_Interface
{
    public:
        Port();
        virtual ~Port();
    protected:
        static const std::type_info& typ;
    private:
};

#endif // PORT_H
