#ifndef EINGANGSBLOCK_BILD_H
#define EINGANGSBLOCK_BILD_H

#include <Block.h>
#include "AusgangImpl.h"


class Eingangsblock_Bild : public Block
{
    public:
        Eingangsblock_Bild();
        enum Typ {IMAGE};

        Eingangsblock_Bild(const string& name) : Block(name)
        {
            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);


            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            image.loadImage("underwater.jpg");
            a1->setzeDaten(&image);
        }

        void update()
        {
            //nothing to do here
//            std::cout << this->name() << ": update()" << std::endl;
        }
        void draw(){
            // nothing to do here
        }
        void trigger(){
            // nothing to do here
        }


    protected:
    private:
        AusgangImpl<ofImage>* a1;
        ofImage image;

};

#endif // EINGANGSBLOCK_BILD_H
