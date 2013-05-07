#ifndef KERNINTERFACE_H
#define KERNINTERFACE_H

/** Interface zur Steuerung des Kerns

Einzige nach Außen sichtbare Schnittstelle.
Über diese kann die komplette Funktionalität des Programmes gesteuert werden.
Es entstehen keine Abhängigkeiten zu den Benutzeroberflächen **/
class kernInterface
{
    public:
        kernInterface();
        virtual ~kernInterface();

        /** Erzeugt ein neues Objekt aus einer Blockklasse des Blocktyps
        @param typ sollte eine Konstante des enum Blocktyp sein, welches von der Klasse BlockInterface zur Verfügung gestellt wird **/
        virtual Block erstelleBlock( Blocktyp typ ) = 0;

        /** entfernt eine Blockinstanz und zugehörige Verbindungen aus dem Programm **/
        virtual bool loescheBlock( Block block ) = 0;

        holeBlockinfo()
        gibt Infos über einen Blocktyp zurück
        holeBlockBibliothek()
        holeBlockListe()
        gibt alle erstellbaren Blocktypen zurück
        holeVerwendeteBloecke()
        gibt alle Blöcke zurück, die im Patch verwendet sind
        holeBlockeigenschaften(Block)
        gibt Einstellungen eines verwendeten Blockes zurück
        setzeBlockeigenschaften(Block, Eigenschaften)
        übernimmt die Eigenschaften aus dem übergebenem Eigenschaftsobjekt
        setzeBlockeigenschaft(Eigenschaft)
        übernimmt einen einzelnen Eigenschaftswert
        setzeVerbindung(Block A, Ausgang A, Block B, Eingang B)
        setzt einen Eingang an einen Ausgang
        holeVerbindungen()
        gibt alle erstellten Verbindungen im Patch zurück
        holeVerbindungen(Block)
        gibt alle erstellten Verbindungen eines Blockes zurück
        loescheVerbindung(Verbindung)
        entfernt eine Verbindung
        startePatch()
        wechselt vom Editormodus in den Abspielmodus
        stoppePatch()
        wechselt vom Abspielmodus in den Editormodus
        patchSpeichern(Pfad)
        speichert den aktuellen Patch in einer Datei unter dem Pfad
        patchLaden(Pfad)
        Lädt den Patch unter angegebenem Pfad
        neuerPatch()
        erzeugt ein neues, leeres Dokument (in neuem Fenster)
        Beobachter
        Subjekt (für Beobachter)









    protected:
    private:
};

#endif // KERNINTERFACE_H
