#ifndef VERARBEITUNGSBLOCK_BINARISIERUNG_H
#define VERARBEITUNGSBLOCK_BINARISIERUNG_H

#include "Block.h"


class Verarbeitungsblock_Binarisierung : public Block
{
    public:
        Verarbeitungsblock_Binarisierung();
        enum Typ {IMAGE};

        Verarbeitungsblock_Binarisierung(const string& name) : Block(name)
        {
            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);

            int IMAGE_HEIGHT = 480;
            int IMAGE_WIDTH = 640;

            schwellwert = 35;

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            a1->setzeDaten(&image);
        }

        void update()
        {
            if(e1->daten()!=nullptr){
                image = *(e1->daten());
                for(int s=0; s<image.getPixelsRef().size(); s++){
                    image.getPixelsRef()[s] = image.getPixelsRef()[s] > schwellwert ? 255 : 0;
                }
            }
        }
        void draw()
        {
            //nothing to do here
        }
        void trigger(int key)
        {
            switch (key){
            case 357:
                if(schwellwert<255){
                    schwellwert++;
                }
                break;
            case 359:
                if(schwellwert>0){
                    schwellwert--;
                }
                break;
            }
            std::cout << this->name() << " Schwellwert: "<< schwellwert << std::endl;
        }

    protected:
    private:
        EingangImpl<ofImage>* e1;
        AusgangImpl<ofImage>* a1;
        ofImage image;
        int schwellwert;
};

#endif // VERARBEITUNGSBLOCK_BINARISIERUNG_H
