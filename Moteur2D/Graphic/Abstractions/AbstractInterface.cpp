


#include "AbstractInterface.h"


void AbstractInterface::setBoundaries(sf::IntRect limits)
{
    m_boundaries = limits;
}


sf::IntRect& AbstractInterface::getBoundaries()
{
    return m_boundaries;
}

const sf::IntRect& AbstractInterface::getBoundaries() const
{
    return m_boundaries;
}

void AbstractInterface::drawObjectIn(const AbstractDrawable& object, sf::RenderTarget& target) const
{
    object.drawIn(target);
}

