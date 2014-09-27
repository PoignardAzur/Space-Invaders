

#ifndef INTERFACE_HEADER
#define INTERFACE_HEADER


#include "AbstractDrawable.h"


class AbstractInterface : public AbstractDrawable
{
    public :
    virtual void setBoundaries(sf::IntRect limits);
    virtual void drawIn(sf::RenderTarget&) const = 0;

    protected :
    virtual sf::IntRect& getBoundaries();
    virtual const sf::IntRect& getBoundaries() const;
    void drawObjectIn(const AbstractDrawable& object, sf::RenderTarget& target) const;

    private :
    sf::IntRect m_boundaries;
};





#endif


