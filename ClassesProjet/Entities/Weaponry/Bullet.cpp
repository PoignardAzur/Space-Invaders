

#include <iostream>
#include "Bullet.h"
#include "../Enemies/Enemy.h"
#include "../PlayerShip.h"

Bullet::Bullet()
{
    BaseVart::PhysicObject::setHitbox(BULLET_HITBOX);
//    m_maxSpeedReached = false;
}

    Bullet(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite);
    void set(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite);

Bullet::Bullet(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite)
{
    BaseVart::PhysicObject::setHitbox(BULLET_HITBOX);
    set(pos, maxSpeed, sprite);
//  m_maxSpeedReached = false;
}


void Bullet::set(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite)
{
    SimpleVart::setSprite(sprite);
    SimpleVart::SimpleHitbox::setPos(pos);
    SimpleVart::SimpleHitbox::setSpeed(sf::Vector2f(0, maxSpeed), false);
    m_power = DEFAULT_BULLET_POWER;
//  m_maxSpeed = maxSpeed;
}

void Bullet::recycle(sf::Vector2f pos, sf::FloatRect visibleZone)
{
    if (!SimpleVart::SimpleHitbox::getHitbox(pos).intersects(visibleZone))
    {
        removeThis();
        return true;
    }

    return false;
}

void Bullet::testHarming(testHarming(sf::Vector2f pos, SpaceShip& target, sf::Vector2f targetPos)
{
    if (testCollision(*this, pos, target, targetPos))
    {
        decreasePower(target.takeDamage(m_power));
    }
}

void Bullet::decreasePower(int powerCut)
{
    if (powerCut >= m_power)
    {
        m_power = 0;
        Vart::removeThis();
    }

    else
    m_power -= powerCut;
}

/*
void Bullet::update(float dt)
{
    if (!m_maxSpeedReached)
    {
        if (m_maxSpeed > 0)
        {
            Vart::PhysicObject::changeAcceleration(sf::Vector2f(0, BULLET_ACCELERATION), true);

            if (Vart::PhysicObject::speed().y > m_maxSpeed)
            {
                Vart::PhysicObject::changeAcceleration(sf::Vector2f(0, 0), false);
                Vart::PhysicObject::changeSpeed(sf::Vector2f(0, m_maxSpeed), false);
                m_maxSpeedReached = true;
            }
        }

        else if (m_maxSpeed < 0)
        {
            Vart::PhysicObject::changeAcceleration(sf::Vector2f(0, - BULLET_ACCELERATION), true);

            if (Vart::PhysicObject::speed().y < m_maxSpeed)
            {
                Vart::PhysicObject::changeAcceleration(sf::Vector2f(0, 0), false);
                Vart::PhysicObject::changeSpeed(sf::Vector2f(0, m_maxSpeed), false);
                m_maxSpeedReached = true;
            }
        }

        else
        {
            Vart::PhysicObject::changeSpeed(sf::Vector2f(0, m_maxSpeed), false);
            m_maxSpeedReached = true;
        }
    }
}*/

