


#ifndef HEADER_AFFICHEUR_VIDE
#define HEADER_AFFICHEUR_VIDE

#include "Abstractions/AbstractDrawable.h"


/*
Affiche basiquement l'apparence des objets.
*/

class VoidDrawer : public AbstractDrawer
{
    private :
//    sf::RenderTarget m_null;
    virtual sf::RenderTarget& target();
//    { return m_null; }

    public :
    virtual void draw(const AbstractDrawable& objet) {}
};


#endif

