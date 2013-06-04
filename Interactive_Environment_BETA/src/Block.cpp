#include "Block.h"

Block::Block()
{
    generierterWert = 0;
}

Block::~Block()
{
    //dtor
}

bool Block::update(){
    if( this->verarbeiteWerte() && this->aktualisiereAusgang()){ //Führt alle notwendigen Schritte von links nach rechts durch und prüft gleichzeitig ob diese geklappt haben
        return true;
    } else {
        return false;
    }
}

Eingang * Block::gebeEingang(unsigned int eingangNr){
    return (eingaenge[eingangNr]);
}

Ausgang * Block::gebeAusgang(unsigned int ausgangNr){
    return (ausgaenge[ausgangNr]);
}

//bool Block::holeWerte(){
//    for (std::size_t i=0; i<eingaenge.size(); i++){ // Geht über jeden Eingang aus dem Eingansvektor
//        if( !(eingaenge[i]->aktualisiereWert())){           // Lässt jeden Eingang den Wert seines zugewießenen Ausgangs abholen
//          return false;                             // Sollte ein Ausgang nicht abgeholt werden können bricht diese Funktion ab und gibt false zurück
//        }
//    }
//    return true;
//}

bool Block::aktualisiereAusgang(){
for (std::size_t i=0; i<ausgaenge.size(); i++){                             // Geht über jeden Ausgang aus dem Ausgangsvektor
        if( !(ausgaenge[i]->aktualisiereWert(generierterWert))){            // Speichert den aktuellen Wert im Ausgang
          return false;                                                     // Sollte ein Ausgang nicht speichern können bricht diese Funktion ab und gibt false zurück
        }
    }
    return true;
}
