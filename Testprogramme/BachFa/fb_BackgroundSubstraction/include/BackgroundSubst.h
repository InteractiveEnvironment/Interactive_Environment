#ifndef BACKGROUNDSUBST_H
#define BACKGROUNDSUBST_H

#include "ofMain.h"


class BackgroundSubst
{
    public:
    //Con- & Destructor
        BackgroundSubst();
        virtual ~BackgroundSubst();

    // Vars


    //Meths
        void setAbsolute(bool);
        void setAutoresize(bool);
        void setBackground();
        void setBackground(ofImage);
        ofImage substract(ofImage);
        void addToBackground(ofImage);
        ofImage getResult();
        void update();
        void setMode(int);


    protected:

    private:
    //Vars
        bool absoluteSet;
        bool autoresizeSet;
        int mode;
        unsigned int limit;
        ofImage background;
        ofImage image;
        ofImage result;
};

#endif // BACKGROUNDSUBST_H
