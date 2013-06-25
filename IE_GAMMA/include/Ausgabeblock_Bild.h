#ifndef AUSGABEBLOCK_BILD_H
#define AUSGABEBLOCK_BILD_H

#include "Block.h"
#include "EingangImpl.h"




class Ausgabeblock_Bild : public Block
{
    public:
        Ausgabeblock_Bild();

        enum Typ {IMAGE};
        int xPos, yPos;

        Ausgabeblock_Bild(const string& name, int _xPos = 20, int _yPos = 20) : Block(name)
        {
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);

            xPos = _xPos;
            yPos = _yPos;

            int IMAGE_HEIGHT = 240;
            int IMAGE_WIDTH = 320;
        }

        void update()
        {
            image = e1->daten();
            if(image!=nullptr)
            {
                image->reloadTexture();
            }
            else
            {
                std::cout << this->name() << ": Image = nullptr" << std::endl;
            }
        }
        void draw()
        {
            if(image!=nullptr)
            {
                image->draw(xPos, yPos);
            }
        }
        void trigger(int key = 0)
        {
            // nothing to do here
        }


    protected:
    private:
        ofImage * image;
        EingangImpl<ofImage>* e1;
};

#endif // AUSGABEBLOCK_BILD_H
