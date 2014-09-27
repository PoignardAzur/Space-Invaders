
#include "Sprite.h"


Sprite::Sprite(const sf::Texture& paraObjet) : m_sprite(paraObjet)
{

}

Sprite::Sprite()
{

}

void Sprite::attribuer(const sf::Texture& paraObjet)
{
    m_sprite.setTexture(paraObjet);
}


sf::Sprite& Sprite::afficher()
{
    return m_sprite;
}

const sf::Sprite& Sprite::afficher() const
{
    return m_sprite;
}


void Sprite::deplacer(const sf::Vector2f& distance)
{
    m_sprite.setPosition(distance);
}

