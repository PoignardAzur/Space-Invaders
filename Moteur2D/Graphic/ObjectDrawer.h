


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "Abstractions/AbstractDrawer.h"

/*
Affiche basiquement l'apparence des objets.
*/

class ObjectDrawer : public AbstractDrawer
{
    public :

    ObjectDrawer(sf::RenderWindow* cible);

    sf::RenderTarget& target();
    void display();

    protected :

    private :
    sf::RenderWindow* m_fenetreCible; /// use-a
};




#endif

