


#include "collisions.h"



bool testerCollision(const sf::IntRect& rectangle1, const sf::IntRect& rectangle2)
{
    return rectangle1.intersects(rectangle2);
}

bool testerCollision(const sf::Vector2f& point1, const sf::IntRect& rectangle2)
{
    return rectangle2.contains(point1.x, point1.y);
}

inline bool testerCollision(const sf::IntRect& rectangle1, const sf::Vector2f& point2)
{
    return testerCollision(point2, rectangle1);
}

