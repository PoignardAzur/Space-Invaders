

#ifndef HEADER_OBJET_AFFICHABLE_ABSTRAIT
#define HEADER_OBJET_AFFICHABLE_ABSTRAIT



#include "AbstractDrawer.h"


/*
Interface d'objet pouvant etre affiche.
*/

class AbstractDrawable
{
    public :

    inline void drawIn(AbstractDrawer& cible) const
    {
        cible.draw(*this);
    }

    virtual void update(float tickSize) {}


    public : // ne pas utiliser, laisser à la classe AbstractDrawer, et implementer dans les classes filles
    virtual void drawIn(sf::RenderTarget&) const = 0;

};





#endif


