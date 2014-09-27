
#include "AbstractSprite.h"



AbstractSprite::AbstractSprite(sf::Drawable* para1, sf::Transformable* para2) : m_sprite(para1), m_geo(para2)
{

}

const sf::Drawable& AbstractSprite::sprite() const
{
    return *m_sprite;
}

sf::Drawable& AbstractSprite::sprite()
{
    return *m_sprite;
}

void AbstractSprite::setPosition(const sf::Vector2f& nposition)
{
    m_geo->setPosition(nposition);
}

