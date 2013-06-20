#ifndef AUSGABEBLOCK_BILD_H
#define AUSGABEBLOCK_BILD_H

#include "Block.h"
#include "EingangImpl.h"




class Ausgabeblock_Bild : public Block
{
    public:
        Ausgabeblock_Bild();
//        virtual ~Ausgabeblock_Bild();

        enum Typ {IMAGE};

        Ausgabeblock_Bild(const string& name) : Block(name)
        {
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);

            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;

            image = new ofImage;
            image->allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
        }

        void update()
        {
            image = e1->daten();
            if(image!=nullptr)
            {
                image->reloadTexture();
                image->draw(20, 20);
            }
            else
            {
                std::cout << "Image = nullptr" << std::endl;
            }
        }


    protected:
    private:
        ofImage * image;
        EingangImpl<ofImage>* e1;
};

#endif // AUSGABEBLOCK_BILD_H
