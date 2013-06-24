#ifndef VERARBEITUNGSBLOCK_BILDSUBSTRAKTION_H
#define VERARBEITUNGSBLOCK_BILDSUBSTRAKTION_H

#include <Block.h>
#include "EingangImpl.h"
#include "AusgangImpl.h"


class Verarbeitungsblock_Bildsubstraktion : public Block
{
    public:
        Verarbeitungsblock_Bildsubstraktion();
        enum Typ {IMAGE, BACKGROUND_IMAGE};

        Verarbeitungsblock_Bildsubstraktion(const string& name) : Block(name)
        {
            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);
            e2 = new EingangImpl<ofImage>("e2");
            this->eingangHinzufuegen(e2);

            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
//            image_e1->allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
//            image_e2->allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            a1->setzeDaten(&image);
        }

        void update()
        {
//            std::cout << this->name() << ": update() start" << std::endl;
            image_e1 = e1->daten();
            image_e2 = e2->daten();
//            std::cout << this->name() << ": update() imageadressen kopiert" << std::endl;

            if((e1->daten()!=nullptr) && (e2->daten()!=nullptr)){
//                std::cout << "Bildsubstraktion: true" << std::endl;
                for(int s=0; s<image.getPixelsRef().size(); s++){
                    image.getPixelsRef()[s] = std::abs( image_e1->getPixelsRef()[s] - image_e2->getPixelsRef()[s] );
                }
            }
        }

        void draw()
        {
            //nothing to do here
        }

        void trigger()
        {
            //nothing to do here
        }

    protected:
    private:
        EingangImpl<ofImage>* e1;
        EingangImpl<ofImage>* e2;
        AusgangImpl<ofImage>* a1;
        ofImage image;
        ofImage * image_e1;
        ofImage * image_e2;
};

#endif // VERARBEITUNGSBLOCK_BILDSUBSTRAKTION_H
