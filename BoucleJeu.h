


#ifndef HEADER_BOUCLE
#define HEADER_BOUCLE

#include "Moteur2D/includes.h"

#define HAUTEUR_FENETRE 400
#define LARGEUR_FENETRE 600


class BoucleJeu : public Gestionnaire
{
    public :

    BoucleJeu(Entrees* nEntrees = 0);

    virtual void MAJ();
 // void finirJeu();

    private :

    Alea m_hasard;
};


#endif
