#ifndef VERARBEITUNGSBLOCK_SCHNAPPSCHUSS_H
#define VERARBEITUNGSBLOCK_SCHNAPPSCHUSS_H

#include <Block.h>
#include "EingangImpl.h"
#include "AusgangImpl.h"


class Verarbeitungsblock_Schnappschuss : public Block
{
    public:
        Verarbeitungsblock_Schnappschuss();
        enum Typ {IMAGE};

        Verarbeitungsblock_Schnappschuss(const string& name) : Block(name)
        {
            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);

            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            a1->setzeDaten(&image);
        }

        void update()
        {
//            std::cout << this->name() << ": update()" << std::endl;
            //nothing to do here
        }
        void draw()
        {
            //nothing to do here
        }
        void trigger()
        {
            std::cout << this->name() << ": trigger()" << std::endl;
            image = *(e1->daten());
//            a1->setzeDaten(&image);
        }

    protected:
    private:
        EingangImpl<ofImage>* e1;
        AusgangImpl<ofImage>* a1;
        ofImage image;

};

#endif // VERARBEITUNGSBLOCK_SCHNAPPSCHUSS_H
