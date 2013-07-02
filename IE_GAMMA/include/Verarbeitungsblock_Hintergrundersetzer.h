#ifndef VERARBEITUNGSBLOCK_HINTERGRUNDERSETZER_H
#define VERARBEITUNGSBLOCK_HINTERGRUNDERSETZER_H

#include "Block.h"
#include "EingangImpl.h"
#include "AusgangImpl.h"

class Verarbeitungsblock_Hintergrundersetzer : public Block
{
    public:
        Verarbeitungsblock_Hintergrundersetzer();
        //Enum Bezeichnungen werden in der gleichen Reihenfolge definiert,
        // wie die Eingänge in den Vector gespeichert werden
        enum Typ {IMAGE, BACKGROUND_IMAGE, MASKEN_IMAGE};

        Verarbeitungsblock_Hintergrundersetzer(const string& name) : Block(name)
        {
            //Ein- und Ausgänge eines konkreten Datentyps werden definiert
            // und im entsprechendem Vector gespeichert (Reihenfolge beachten, siehe Enum weiter oben)
            e1 = new EingangImpl<ofImage>("e1");
            this->eingangHinzufuegen(e1);
            e2_Background = new EingangImpl<ofImage>("e2");
            this->eingangHinzufuegen(e2_Background);
            e3_Maske = new EingangImpl<ofImage>("e3");
            this->eingangHinzufuegen(e3_Maske);

            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);

            //TODO: Dynamisch Größe anpassen
            int IMAGE_HEIGHT = 480;
            int IMAGE_WIDTH = 640;

            //jedes konkrete ofImage muss mit allocate Speicher reservieren, bevor es verwendet werden kann
            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
            //Die Adresse des Bildes (bzw. der Daten) wird dem Ausgang übergeben
            a1->setzeDaten(&image);

            //Kein Destruktor,
            // oder Destruktor, welcher Elterndestruktor aufruft
        }

        void update()
        {
            //Aktuelle Daten werden aus den Eingängen geholt
            image_e1 = e1->daten();
            image_e2_Background = e2_Background->daten();
            image_e3_Maske = e3_Maske->daten();

            //Die Maske wird verwendet um entweder das eine oder das andere Bild einzublenden
            if((e1->daten()!=nullptr) && (e2_Background->daten()!=nullptr) && (e3_Maske->daten() != nullptr)){
                for(int s=0, b=0; s<image.getPixelsRef().size(); s+=3, b++){
                    if(image_e3_Maske->getPixelsRef()[s] > 0
                       || image_e3_Maske->getPixelsRef()[s+1] > 0
                       || image_e3_Maske->getPixelsRef()[s+2] > 0){
                        for(int i=0; i<3; i++){
                            image.getPixelsRef()[s+i] = image_e1->getPixelsRef()[s+i];
                        }
                    }else{
                        for(int i=0; i<3; i++){
                            image.getPixelsRef()[s+i] = image_e2_Background->getPixelsRef()[s+i];
                        }
                    }
                }
            }
        }
        void draw(){
            // nothing to do here
        }
        void trigger(int key = 0){
            // nothing to do here
        }


    protected:
    private:
        EingangImpl<ofImage>* e1;
        EingangImpl<ofImage>* e2_Background;
        EingangImpl<ofImage>* e3_Maske;
        AusgangImpl<ofImage>* a1;
        ofImage image;
        ofImage * image_e1;
        ofImage * image_e2_Background;
        ofImage * image_e3_Maske;
};

#endif // VERARBEITUNGSBLOCK_HINTERGRUNDERSETZER_H
