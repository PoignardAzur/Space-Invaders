

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Niveau.h"


class Gestionnaire
{
    public :

    Gestionnaire(Niveau* niveauJoue = 0, Entrees* tableauEntrees = 0, sf::RenderWindow* cible = 0);
    void attribuer(Niveau* niveauJoue, Entrees* tableauEntrees, sf::RenderWindow* cible);

    virtual void MAJ();
    virtual bool continuer();


    private :

    boost::shared_ptr<Niveau> m_niveauJoue; // has-a
    boost::shared_ptr<Entrees> m_entrees; // has-a
    boost::shared_ptr<AfficheurObjets> m_fenetre; // has-a
    sf::RenderWindow* m_cible; // has-a
};


#endif

