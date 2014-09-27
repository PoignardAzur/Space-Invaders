
#include "Sprite.h"


CtB::Sprite::Sprite(const Parametres& paraObjet) : m_sprite(*( paraObjet.adresseImage() ))
{

}



sf::Sprite& CtB::Sprite::afficher()
{
    return m_sprite;
}

const sf::Sprite& CtB::Sprite::afficher() const
{
    return m_sprite;
}


void CtB::Sprite::deplacer(const sf::Vector2f& distance)
{
    m_sprite.setPosition(distance);
}

