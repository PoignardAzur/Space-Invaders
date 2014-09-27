
#include "Sprite.h"



Sprite::Sprite(sf::Drawable* para1, sf::Transformable* para2) : m_sprite(para1), m_geo(para2)
{

}

const sf::Drawable& Sprite::sprite() const
{
    return *m_sprite;
}

sf::Drawable& Sprite::sprite()
{
    return *m_sprite;
}

void Sprite::setPosition(const sf::Vector2f& nposition)
{
    m_geo->setPosition(nposition);
}

