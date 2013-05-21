#ifndef KERNINTERFACE_H
#define KERNINTERFACE_H
/** TODO:   Verbindungsobjekt/struct definieren
            Blockobjekt/struckt definieren
            Blockinfoobjekt/struct definieren
**/


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
        @param typ sollte eine Konstante des enum Blocktyp sein, welches von der Klasse BlockInterface zur Verfügung gestellt wird
        @return gibt die ID des Blockelementes zurück **/
        virtual char erstelleBlock( blocktyp typ ) = 0;

        /** entfernt eine Blockinstanz und zugehörige Verbindungen aus dem Programm **/
        virtual bool loescheBlock( char blockId ) = 0;

        /** Gibt Infos über einen Blocktyp zurück **/
        virtual Blockeigenschaften holeBlockinfo( Blocktyp block ) = 0;

        /** Bibliothek auslesen sortiert nach Kategorie
        z.B. Inputs, Outputs, Mathematik, usw...
        @return Gibt ein Array mit den verschiedenen Blockkategorien zurück **/
        virtual blockkategorie[] holeBlockBibliothek() = 0;

        /** @return Gibt ein Array mit den verschiedenen Blocktypen zurück **/
        virtual blocktyp[] holeBlockListe() = 0;

        /** Gibt ein Array mit den IDs der erstellten Blöcke zurück **/
        virtual char[] holeVerwendeteBloecke() = 0;

        /** Gibt Einstellungen eines verwendeten Blockes zurück **/
        virtual blockEigenschaften holeBlockeigenschaften( blockId ) = 0;

        /** Überschreibt die Eigenschaften des Blocks mit den übergebenen Eigenschaften
        @param blockId ID des Blocks
        @param blockEigenschaften Objekt mit Eigenschaften und zugehörigen Werten **/
        virtual bool setzeBlockeigenschaften(blockId, blockEigenschaften) = 0;

        /** Überschreibt einen einzelnen Eigenschaftswert des Blocks **/
        setzeBlockeigenschaft(blockId, Eigenschaft, Wert) = 0;

        setzt einen Eingang an einen Ausgang
        virtual bool setzeVerbindung(blockId blockA, blockAusgang ausgang, blockId blockE, blockEingang eingang) = 0;

        /** Bestehende Verbindungen abfragen
        @return gibt alle erstellten Verbindungen im Patch zurück **/
        virtual verbindung[] holeVerbindungen() = 0;

        /** Bestehende Verbindungen eines Blocks abfragen
        @return gibt alle erstellten Verbindungen eines Blockes zurück **/
        virtual verbindung[] holeVerbindungen( blockId ) = 0;

        /** Entfernt eine Verbindung
        @param verbindung **/
        virtual bool loescheVerbindung( verbindung ) = 0;

        /** Wechselt vom Editormodus in den Abspielmodus **/
        virtual bool startePatch() = 0;

        /** wechselt vom Abspielmodus in den Editormodus **/
        virtual bool stoppePatch() = 0;

        /** speichert den aktuellen Patch in einer Datei unter dem Pfad **/
        virtual bool patchSpeichern(Pfad) = 0;

        /** Lädt den Patch unter angegebenem Pfad **/
        virtual bool patchLaden(Pfad) = 0;

        /** erzeugt ein neues, leeres Dokument ( evtl. in neuem Fenster) **/
        virtual bool neuerPatch() = 0;

        /** Beobachtermuster für Fehlermeldungen **/
        virtual bool abboniereFehlermeldungen(Beobachter b) = 0;

    protected:
    private:
};

#endif // KERNINTERFACE_H
