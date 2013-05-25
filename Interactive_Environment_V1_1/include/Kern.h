#ifndef KERN_H
#define KERN_H

/** Basisklasse des Models
    Wird im Programm nur ein einziges Mal instanziiert
    Erstellt und verwaltet alle Blockelemente
    Erstellt und verwaltet alle Verbindungen zwischen den Blockelementen
    Wechselt zwischen Editor- und Abspielmodus
**/
class Kern
{
    public:
        Kern();
        virtual ~Kern();

        /** Erstellt neuen Block
            @param gibt den Blocktyp an
            @return gibt die ID des neuen Blockelementes zurück **/
        int erstelleBlock(blocktyp typ);

        /** Wechselt in den Abspielmodus **/
        bool startePatch();
        /** Wechselt in den Editormodus **/
        bool stoppePatch();

    protected:
    private:
        /** Array beinhaltet alle erstellten BLockelemente **/
        Block blockListe;

        /** Aktueller Modus: sollte am Besten über Strategiemuster realisiert werden **/
        string modus;
};

#endif // KERN_H
