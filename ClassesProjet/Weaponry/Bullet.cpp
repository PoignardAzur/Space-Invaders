

#include <iostream>
#include "Bullet.h"
#include "../Enemies/Enemy.h"
#include "../PlayerShip.h"

Bullet::Bullet()
{
    BaseVart::PhysicObject::setHitbox(BULLET_HITBOX);
//    m_maxSpeedReached = false;
}


Bullet::Bullet(sf::Vector2f pos, float maxSpeed, const sf::Sprite& bulletSprite)
{
    BaseVart::PhysicObject::setHitbox(BULLET_HITBOX);
    set(pos, maxSpeed, bulletSprite);
//  m_maxSpeedReached = false;
}


void Bullet::set(sf::Vector2f pos, float maxSpeed, const sf::Sprite& bulletSprite)
{
    BaseVart::PhysicObject::move(pos, false);
    BaseVart::setSprite(bulletSprite);
    BaseVart::setSpriteRelativePosition(sf::Vector2f(- bulletSprite.getGlobalBounds().width / 2, - bulletSprite.getGlobalBounds().height / 2));

    BaseVart::PhysicObject::changeSpeed(sf::Vector2f(0, maxSpeed), false);
    m_power = DEFAULT_BULLET_POWER;
//  m_maxSpeed = maxSpeed;
}

void Bullet::recycle(sf::FloatRect visibleZone)
{
    if (! testCollision(Vart::PhysicObject::placedBox(), visibleZone))
    {
        Vart::removeThis();
    }
}

void Bullet::testHarming(HurtableEntity& e, const PhysicObject& o)
{
    if (testCollision(*this, o))
    {
        decreasePower(e.takeDamage(m_power));
    }
}

void Bullet::testHarming(Enemy& e)
{
    testHarming(e,e);
}

void Bullet::testHarming(PlayerShip& e)
{
    testHarming(e,e);
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


void Bullet::update(float tickSize)
{
    Vart::update(tickSize);
/*
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
    }*/
}

