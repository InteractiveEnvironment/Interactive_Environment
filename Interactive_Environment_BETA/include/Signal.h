#ifndef SIGNAL_H
#define SIGNAL_H

#include "ofImage.h"


class Signal
{
    public:
        Signal();
        virtual ~Signal();

        bool boolWert;
        char charWert;
        int intWert;
        float floatWert;
        string stringWert;
        ofImage imageWert;
    protected:
        /** Enthält einen String mit dem Namen des Datentypes der gesetzt ist
            z.B.: "string" oder "image" **/
        string gesetzterWert;
    private:
};

#endif // SIGNAL_H
