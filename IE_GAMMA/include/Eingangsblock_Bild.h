#ifndef EINGANGSBLOCK_BILD_H
#define EINGANGSBLOCK_BILD_H
#include <vector>

#include "Block.h"
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


            int IMAGE_HEIGHT = 480;
            int IMAGE_WIDTH = 640;

            bilderBibCounter = 0;

            bilderBib.push_back("640x480/moon.jpg");
            bilderBib.push_back("640x480/underwater.jpg");
            bilderBib.push_back("640x480/forest.jpg");
//            bilderBib.push_back("640x480/underwater_2.jpg");
            bilderBib.push_back("640x480/mario.jpg");
//            bilderBib.push_back("640x480/party.jpg");


            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            image.loadImage(bilderBib[0]);
            a1->setzeDaten(&image);
        }

        void update()
        {
            //nothing to do here
        }
        void draw(){
            // nothing to do here
        }
        void trigger(int key = 0){
            switch(key){
            case 356:
                if(bilderBibCounter > 0){
                    bilderBibCounter--;
                }else{
                    bilderBibCounter = bilderBib.size()-1;
                }
                break;
            case 358:
                if(bilderBibCounter < bilderBib.size()-1){
                    bilderBibCounter++;
                }else{
                    bilderBibCounter = 0;
                }
                break;
            }
            image.loadImage(bilderBib[bilderBibCounter]);
            std::cout << this->name() << " Bild Nr.: " << bilderBibCounter << " geladen" << std::endl;
        }


    protected:
    private:
        AusgangImpl<ofImage>* a1;
        ofImage image;
        std::vector<string> bilderBib;
        int bilderBibCounter;
};

#endif // EINGANGSBLOCK_BILD_H
