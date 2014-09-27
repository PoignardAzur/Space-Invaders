

#include "Weapon.h"
#include <assert.h>


Weapon::Weapon(float shootCoolDown, float timeToNextShoot)
{
    setStats(shootCoolDown, timeToNextShoot);
    m_ammo = -1;
}

Weapon::Weapon(const Weapon& otherWeapon) : m_timer(otherWeapon.m_timer), m_bulletSprite(otherWeapon.m_bulletSprite), p_bulletArray(otherWeapon.p_bulletArray)
{
    m_ammo = -1;
}

Weapon::Weapon(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    setBullets(bulletSpr, bulletArray);
    m_ammo = -1;
}

void Weapon::setStats(float shootCoolDown, float timeToNextShoot)
{
    m_timer.setMaxTime(shootCoolDown);
    m_timer.setTime(timeToNextShoot);
}


void Weapon::setBulletSprite(const sf::Sprite& bulletSpr)
{
    m_bulletSprite = bulletSpr;
}

void Weapon::setBulletArray(VartArray<Bullet>* bulletArray)
{
    p_bulletArray = bulletArray;
}

void Weapon::setBullets(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    m_bulletSprite = bulletSpr;
    p_bulletArray = bulletArray;
}

bool Weapon::update(float tickSize)
{
    m_timer.decrement(tickSize);
    return readyToShoot();
}

bool Weapon::readyToShoot() const
{
    return ammo() != 0 && !(m_timer.time() > 0);
}

bool Weapon::tryToShoot(const sf::Vector2f& pos, float speed)
{
    if (!readyToShoot())
    return false;

/// else
    shoot(pos, speed);
    m_timer.resetTimeToMax();
    assert(!readyToShoot());

    if (ammo() > 0)
    setAmmoCount(-1, true);

    return true;
}

void Weapon::shoot(const sf::Vector2f& bulletPos, float bulletSpeed)
{
    m_bulletCenter = sf::Vector2f(4, 16);
    p_bulletArray->add( new Bullet(bulletPos - m_bulletCenter, bulletSpeed, m_bulletSprite) );
}

int Weapon::ammo() const
{
    return m_ammo;
}


void Weapon::setAmmoCount(int a, bool relative)
{
    if (relative)
    m_ammo += a;

    else
    m_ammo = a;
}


