

#ifndef HEADER_COLLISIONS
#define HEADER_COLLISIONS

#include <SFML/Graphics.hpp>

// The functions are inline because they're quite simple
// They test wether two objects intersect

inline bool testCollision(const sf::FloatRect& rectangle1, const sf::FloatRect& rectangle2)
{
    return rectangle1.intersects(rectangle2);
}

inline bool testCollision(const sf::Vector2f& point1, const sf::FloatRect& rectangle2)
{
    return rectangle2.contains(point1.x, point1.y);
}

inline bool testCollision(const sf::FloatRect& rectangle1, const sf::Vector2f& point2)
{
    return rectangle1.contains(point2.x, point2.y);
}

inline bool testCollision(const sf::Vector2f& point1, const sf::Vector2f& point2)
{
    return point1 == point2;
}


#endif

