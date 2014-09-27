

#ifndef HEADER_SPRITE
#define HEADER_SPRITE



#include "Drawable.h"

// The simplest form of sprite
class Sprite : public DrawableObject
{
    public :

    Sprite() {}
    Sprite(const sf::Sprite& image);
    void set(const sf::Sprite& image);
    void setPosition(const sf::Vector2f& nposition); // define better ?

    static void createMaskFromColor(sf::Texture&, const sf::Color &color, sf::Uint8 alpha=0);

    protected :
    virtual const sf::Drawable& sprite() const;
    virtual sf::Drawable& sprite();

    private :

    sf::Sprite m_image;
};





#endif


