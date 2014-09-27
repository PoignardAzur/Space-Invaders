

#ifndef HEADER_COLLISIONS
#define HEADER_COLLISIONS

#include "ObjetPhysique.h"

bool collision(const sf::IntRect& rectangle1, const sf::IntRect& rectangle2);
bool collision(const sf::Vector2f& rectangle1, const sf::IntRect& rectangle2);
inline bool collision(const sf::IntRect& rectangle1, const sf::Vector2f& rectangle2);


#endif

