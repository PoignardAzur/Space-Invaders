

#include "Hitbox.h"


bool CtB::collision(const sf::IntRect& rectangle1, const sf::IntRect& rectangle2)
{
    if (rectangle1.left > rectangle2.left + rectangle2.width)
    return false;
/// else
    if (rectangle1.left + rectangle1.width < rectangle2.left)
    return false;
/// else
    if (rectangle1.top > rectangle2.top + rectangle2.height)
    return false;
/// else
    if (rectangle1.top + rectangle1.height < rectangle2.top)
    return false;
/// else
    return true;
}

bool CtB::collision(const sf::Vector2f& point1, const sf::IntRect& rectangle2)
{
    if (rectangle2.left > point1.x)
    return false;
/// else
    if (rectangle2.left + rectangle2.width < point1.x)
    return false;
/// else
    if (rectangle2.top > point1.y)
    return false;
/// else
    if (rectangle2.top + rectangle2.height < point1.y)
    return false;
/// else
    return true;
}

inline bool CtB::collision(const sf::IntRect& rectangle1, const sf::Vector2f& point2)
{
    return collision(point2, rectangle1);

}

bool CtB::collision(const CtB::Hitbox& rectangle1, const CtB::Hitbox& rectangle2)
{
    return collision(rectangle1.rectangle(), rectangle2.rectangle());
}


