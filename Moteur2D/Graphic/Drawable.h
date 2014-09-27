

#ifndef HEADER_OBJET_AFFICHABLE
#define HEADER_OBJET_AFFICHABLE



#include "Abstractions/AbstractDrawable.h"


/*
Interface d'objet pouvant etre affiche,
base sur un sprite sfml et depla�able.
*/

class DrawableObject : public AbstractDrawable
{
    protected :
    virtual const sf::Drawable& sprite() const = 0;
    virtual sf::Drawable& sprite() = 0;

    public :
    void drawIn(sf::RenderTarget& cible) const
    {
        cible.draw(sprite());
    }
};





#endif

