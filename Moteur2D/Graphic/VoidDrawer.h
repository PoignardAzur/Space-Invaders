


#ifndef HEADER_AFFICHEUR_VIDE
#define HEADER_AFFICHEUR_VIDE

#include "Abstractions/AbstractDrawable.h"


/*
N'affiche rien du tout. Peut remplacer n'importe quel abstractdrawer.
*/

class VoidDrawer : public AbstractDrawer
{
    private :
    sf::RenderWindow m_null;
    sf::RenderTarget& target()
    { return m_null; }

    public :
    void draw(const AbstractDrawable& objet) {}
};


#endif

