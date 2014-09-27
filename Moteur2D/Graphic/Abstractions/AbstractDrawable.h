

#ifndef HEADER_OBJET_AFFICHABLE_ABSTRAIT
#define HEADER_OBJET_AFFICHABLE_ABSTRAIT



#include "AbstractDrawer.h"


/*
Interface d'objet pouvant etre affiche.
*/
class AbstractInterface;

class AbstractDrawable
{
    public :

    inline void drawIn(AbstractDrawer& cible) const
    {
        cible.draw(*this);
    }

    virtual void update(float tickSize) {}                              // for animations


    protected :
    virtual void drawIn(sf::RenderTarget&) const = 0;                   // the function to define for child classes to work
    friend void AbstractDrawer::draw(const AbstractDrawable&);
    friend class AbstractInterface;
};





#endif


