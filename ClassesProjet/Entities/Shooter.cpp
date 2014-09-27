


#include "Shooter.h"



Shooter::Shooter(float nAmmo, float nMaxAmmo)
{
    set(nAmmo, nMaxAmmo);
}

void Shooter::set(float nAmmo, float nMaxAmmo)
{
    m_ammo = nAmmo;
    m_maxAmmo = nMaxAmmo;
}

void Shooter::trytoShoot(Bullet* what)
{
    if (ammo() >= minAmmoToShoot())
    shoot(what);

    else
    delete what;
}

void Shooter::reload(float ammoAdded)
{
    m_ammo += ammoAdded;

    if (m_ammo > maxAmmo())
    m_ammo = maxAmmo();
}

void Shooter::shoot(Bullet* what)
{
    m_ammo -= ammoUsed();
    shootProjectile(what);
}

float Shooter::minAmmoToShoot()
{
    return maxAmmo();
}

float Shooter::ammo()
{
    return m_ammo;
}

float Shooter::maxAmmo()
{
    return m_maxAmmo;
}

float Shooter::ammoUsed()
{
    return minAmmoToShoot();
}




void Shooter::shootProjectile(Bullet* what)
{
    delete what;
//    m_target->add(what);
}

