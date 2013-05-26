#ifndef BLOCKINTERFACE_H
#define BLOCKINTERFACE_H


class BlockInterface
{
    public:
        BlockInterface();
        virtual ~BlockInterface();

        virtual bool update() = 0;

        virtual bool setzeEingang() = 0;

        /** TODO:
            Möglichkeit die zur Verfügung gestellten Ausgänge abzurufen

            Rekursives Abarbeiten der Eingänge

            Zurückgeben von unterschiedlichsten Rückgabetypen
            **/

    protected:
    private:
};

#endif // BLOCKINTERFACE_H
