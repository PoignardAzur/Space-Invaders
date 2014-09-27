

#ifndef HEADER_SPRITE
#define HEADER_SPRITE

#include "Drawable.h"


/*
Affiche un sprite. Peut-etre en faire une base de hierarchie ?
*/
class Sprite : public DrawableObject
{
    public :
    Sprite(sf::Drawable* para1, sf::Transformable* para2 = 0);
    void setPosition(const sf::Vector2f& nposition);

    protected :
    virtual const sf::Drawable& sprite() const;
    virtual sf::Drawable& sprite();

    private :
    boost::shared_ptr<sf::Drawable> m_sprite; // has-a
    sf::Transformable* m_geo; // has-a
};




#endif
