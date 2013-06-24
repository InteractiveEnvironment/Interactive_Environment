#ifndef VERARBEITUNGSBLOCK_BINARISIERUNG_H
#define VERARBEITUNGSBLOCK_BINARISIERUNG_H

#include <Block.h>


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

            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            a1->setzeDaten(&image);
        }

        void update()
        {
            image = *(e1->daten());

            for(int s=0; s<image.getPixelsRef().size(); s++){
                image.getPixelsRef()[s] = image.getPixelsRef()[s] > 35 ? 255 : 0;
            }
        }
        void draw()
        {
            //nothing to do here
        }
        void trigger()
        {

        }

    protected:
    private:
        EingangImpl<ofImage>* e1;
        AusgangImpl<ofImage>* a1;
        ofImage image;
};

#endif // VERARBEITUNGSBLOCK_BINARISIERUNG_H
