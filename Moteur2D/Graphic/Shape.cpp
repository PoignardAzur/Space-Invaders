
#include "Shape.h"


DrawableShape::DrawableShape(sf::Shape* forme) : m_sprite(forme)
{

}



sf::Shape& DrawableShape::sprite()
{
    return *m_sprite;
}

const sf::Shape& DrawableShape::sprite() const
{
    return *m_sprite;
}


void DrawableShape::setPosition(const sf::Vector2f& npos)
{
    m_sprite->setPosition(npos);
}

