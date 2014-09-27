

#ifndef HEADER_SPRITE_ABSTRAIT
#define HEADER_SPRITE_ABSTRAIT

#include "Drawable.h"


/*
Affiche un sprite. Peut-etre en faire une base de hierarchie ?
*/

/*
Mettre à jour ou oublier
*/
class AbstractSprite : public DrawableObject
{
    public :
    AbstractSprite(sf::Drawable* para1, sf::Transformable* para2 = 0);
    void set(sf::Drawable* para1, sf::Transformable* para2 = 0);
    void setPosition(const sf::Vector2f& nposition);

    protected :
    virtual const sf::Drawable& sprite() const;
    virtual sf::Drawable& sprite();

    private :
    boost::shared_ptr<sf::Drawable> m_sprite; // has-a
    boost::shared_ptr<sf::Transformable> m_geo; // has-a
};




#endif

