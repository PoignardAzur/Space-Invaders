

#include "Weapon.h"
#include <assert.h>


Weapon::Weapon(float shootCoolDown, float timeToNextShoot)
{
    set(shootCoolDown, timeToNextShoot);
}

Weapon::Weapon(const Weapon& otherWeapon) : m_bulletSprite(otherWeapon.m_bulletSprite), p_bulletArray(otherWeapon.p_bulletArray), m_timer(otherWeapon.m_timer)
{

}

Weapon::Weapon(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    set(bulletSpr, bulletArray);
}

void Weapon::set(float shootCoolDown, float timeToNextShoot)
{
    m_timer.setMaxTime(shootCoolDown);
    m_timer.setTime(timeToNextShoot);
}


void Weapon::set(const sf::Sprite& bulletSpr)
{
    m_bulletSprite = bulletSpr;
}

void Weapon::set(VartArray<Bullet>* bulletArray)
{
    p_bulletArray = bulletArray;
}

void Weapon::set(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    m_bulletSprite = bulletSpr;
    p_bulletArray = bulletArray;
}

bool Weapon::update(float tickSize)
{
    m_timer.decrement(tickSize);
    return readyToShoot();
}

bool Weapon::readyToShoot()
{
    return !(m_timer.time() > 0);
}

bool Weapon::tryToShoot(const sf::Vector2f& pos, float speed)
{
    if (!readyToShoot())
    return false;

/// else
    shoot(pos, speed);
    m_timer.resetTimeToMax();
    assert(!readyToShoot());
    return true;
}

void Weapon::shoot(const sf::Vector2f& pos, float speed)
{
    m_bulletCenter = sf::Vector2f(4, 16);
    p_bulletArray->add( new Bullet(pos - m_bulletCenter, speed, new Sprite(m_bulletSprite)) );
}


