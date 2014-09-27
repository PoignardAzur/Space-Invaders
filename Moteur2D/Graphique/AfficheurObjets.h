


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "ObjetAffichable.h"
#include "ParametresAffichage.h"

#define LIMITE_NOMBRE_FPS 60


class AfficheurObjets
{
    public :

    AfficheurObjets(sf::RenderTarget* cible);

    void afficher(const ObjetAffichable& objet, const ParametresAffichage& para);
    void afficher(const ObjetAffichable& objet);

    void effacer();

    protected :

    private :

    sf::RenderTarget* m_fenetreCible; /// use-a
};




#endif

