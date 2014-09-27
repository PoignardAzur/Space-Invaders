



#include "ShootingEnemy.h"



ShootingEnemy::ShootingEnemy()
{

}

ShootingEnemy::ShootingEnemy(const Weapon& w) : m_weapon(w)
{

}

void ShootingEnemy::set(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    m_weapon.set(bulletSpr, bulletArray);
}

void ShootingEnemy::set(float shootCoolDown, float timeToNextShoot)
{
    m_weapon.set(shootCoolDown, timeToNextShoot);
}

void ShootingEnemy::setHitbox(const PhysicObject& hitbox)
{
    Enemy::setHitbox(hitbox);
    m_center = center(hitbox.internBox());
}


void ShootingEnemy::update(float tickSize)
{
    Enemy::update(tickSize);
    m_weapon.update(tickSize);
    m_weapon.tryToShoot(position() + m_center, -MAX_BULLET_SPEED);
}


