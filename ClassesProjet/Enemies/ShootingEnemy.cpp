



#include "ShootingEnemy.h"



ShootingEnemy::ShootingEnemy()
{

}

ShootingEnemy::ShootingEnemy(const Weapon& w) : m_weapon(w)
{

}

void ShootingEnemy::setBullets(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray)
{
    m_weapon.setBullets(bulletSpr, bulletArray);
}

void ShootingEnemy::setStats(float shootCoolDown, float timeToNextShoot)
{
    m_weapon.setStats(shootCoolDown, timeToNextShoot);
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


