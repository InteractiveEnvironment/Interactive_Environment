#ifndef PATCH_H
#define PATCH_H


class patch
{
    public:
        patch();
        virtual ~patch();
    protected:
    private:
        /** Die Anzahl der Blöcke in einem Patch **/
        int anzahlBloecke;
        /** Steuer- oder Editormodus **/
        int Modus;
};

#endif // PATCH_H
