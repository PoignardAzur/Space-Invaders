


#include "ParametresVart.h"



ParaVart::ParaVart()
{

}

ParaVart::ParaVart(const sf::Texture& nSprite, const sf::IntRect& nHitbox, const sf::Vector2f& nVitesse)
{
    attribuer(nSprite, nHitbox, nVitesse);
}

void ParaVart::attribuer(const sf::Texture& nSprite, const sf::IntRect& nHitbox, const sf::Vector2f& nVitesse)
{
    m_sprite.attribuer(nSprite);
    m_hitbox  = nHitbox;
    m_vitesse = nVitesse;
}

void ParaVart::attribuer(std::istream& flux, std::map<std::string, Sprite>& tableauSprites)
{
    std::string cle;
    flux >> cle;
    m_sprite = tableauSprites[cle];

    flux >> m_hitbox.top;
    flux >> m_hitbox.left;
    flux >> m_hitbox.height;
    flux >> m_hitbox.width;

    flux >> m_vitesse.x;
    flux >> m_vitesse.y;
}




Sprite ParaVart::sprite() const
{
    return m_sprite;
}

sf::IntRect ParaVart::hitbox() const
{
    return m_hitbox;
}

sf::Vector2f ParaVart::vitesse() const
{
    return m_vitesse;
}


