


#include "Enemy.h"


Enemy::Enemy(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesseY, float accelerationY, float maxSpeed)
{
    define(vie, spr, hitbox, nPosition, vitesseY, accelerationY, maxSpeed);
}

void Enemy::define(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesseY, float accelerationY, float maxSpeed)
{
    Ship::define(vie, spr, hitbox, nPosition, vitesseY, accelerationY);
    m_maxSpeed = maxSpeed;
}

void Enemy::update(float ticks)
{
    Ship::update(ticks);
    move(ticks);
}

void Enemy::move(float ticks)
{
    if (b_isEscaping);

    else
    {
        if (Ship::speed().y >= m_maxSpeed)
        {
            Ship::changeSpeed(sf::Vector2f(0,m_maxSpeed));
            Ship::changeAcceleration(sf::Vector2f(0,0));
        }
    }
}

void Enemy::flee()
{
    b_isEscaping = true;
    Ship::changeSpeed(-Ship::speed());
    Ship::changeAcceleration(-Ship::acceleration());
}


