
#ifndef HEADER_PARAMETRES_VART
#define HEADER_PARAMETRES_VART


#include "Vart.h"
#include <istream>
#include <string>
#include <map>

class ParaVart
{
    public :

    ParaVart();
    ParaVart(const sf::Texture& nSprite, const sf::IntRect& nHitbox, const sf::Vector2f& nVitesse);

    void attribuer(const sf::Texture& nSprite, const sf::IntRect& nHitbox, const sf::Vector2f& nVitesse);
    void attribuer(std::istream& flux, std::map<std::string, Sprite>& tableauSprites);

    Sprite sprite() const;
    sf::IntRect hitbox() const;
    sf::Vector2f vitesse() const;


    private :

    Sprite m_sprite;
    sf::IntRect m_hitbox;
    sf::Vector2f m_vitesse;
};




#endif

