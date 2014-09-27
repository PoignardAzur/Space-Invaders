


#ifndef HEADER_ARME
#define HEADER_ARME


#include "Moteur2D/Jeu/Emetteur.h"


template <typename T>
class Arme : public Emetteur<T>
{
    public :
    virtual void MAJ() = 0;

    protected :
    virtual bool peutTirer() = 0;
};



#endif
