

#include "Sprite.h"


Sprite::Sprite(const sf::Sprite& image)
{
    set(image);
}

void Sprite::set(const sf::Sprite& image)
{
    m_image = image;
}

const sf::Drawable& Sprite::sprite() const
{
    return m_image;
}

sf::Drawable& Sprite::sprite()
{
    return m_image;
}

void Sprite::setPosition(const sf::Vector2f& nposition)
{
    m_image.setPosition(nposition);
}


void Sprite::createMaskFromColor(sf::Texture& t, const sf::Color &color, sf::Uint8 alpha)
{
    sf::Image i(t.copyToImage());
    i.createMaskFromColor(color, alpha);
    t.loadFromImage(i);
}

