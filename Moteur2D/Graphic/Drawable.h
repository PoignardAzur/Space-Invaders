

#ifndef HEADER_OBJET_AFFICHABLE
#define HEADER_OBJET_AFFICHABLE



#include "Abstractions/AbstractDrawable.h"


/*
Interface d'objet pouvant etre affiche,
base sur un sprite sfml et deplaçable.
*/

class DrawableObject : public AbstractDrawable
{
    protected :
    virtual const sf::Drawable& sprite() const = 0;         // The two functions to define
    virtual sf::Drawable& sprite() = 0;                     // for child classes to work

    public :
    void drawIn(sf::RenderTarget& cible) const
    {
        cible.draw(sprite());
    }
};





#endif

