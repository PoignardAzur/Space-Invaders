


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "Abstractions/AbstractDrawer.h"

/*
Affiche basiquement l'apparence des objets.
*/

class ObjectDrawer : public AbstractDrawer
{
    public :

    ObjectDrawer(sf::RenderTarget* cible);

    sf::RenderTarget& target();
//    void display();

    protected :

    private :
    sf::RenderTarget* m_fenetreCible; /// use-a
};




#endif

