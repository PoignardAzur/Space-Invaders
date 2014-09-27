

#include "Enemy.h"
#include <cassert>


Enemy::Enemy()
{

}


Enemy::Enemy(sf::IntRect spawnZone, Alea& dice, Sprite* spr, sf::IntRect hitbox, float nSpeed, int hp, int nScore)
{
    set(spawnZone, dice, spr, hitbox, nSpeed, hp, nScore);
}


void Enemy::set(sf::IntRect spawnZone, Alea& dice, Sprite* spr, sf::IntRect hitbox, float nSpeed, int hp, int nScore)
{
    m_has_entered = false;

    setHitbox(hitbox);
    Vart::setSprite(spr);
//  Vart::PhysicObject::move(sf::Vector2f(50, -20));/*
    Vart::PhysicObject::move(sf::Vector2f(dice(spawnZone.left + hitbox.left, spawnZone.left - hitbox.left + spawnZone.width - hitbox.width),
                                          dice(spawnZone.top + hitbox.top, spawnZone.top - hitbox.top + spawnZone.height - hitbox.height) ), false);//*/

    Vart::PhysicObject::changeSpeed(sf::Vector2f(0, nSpeed));

    m_hp = hp;
    m_score = nScore;
}

void Enemy::setHitbox(const PhysicObject& hitbox)
{
    Vart::setHitbox(hitbox);
}

bool Enemy::recycle(const sf::IntRect& visibleZone)
{
    if (testCollision(Vart::PhysicObject::placedBox(), visibleZone))
    {
        m_has_entered = true;
    }

    else if (m_has_entered)
    {
        Vart::removeThis();
        return true;
    }

    return false;
}

int Enemy::takeDamage(int dm)
{
    if (!m_has_entered)
    {
        return 0;
    }

    if (m_hp > dm)
    m_hp -= dm;

    else
    {
        explode();
        dm = m_hp;
        m_hp = 0;
    }

    return dm;
}

bool Enemy::isDead() const
{
    return Vart::doDelete();
}

int Enemy::score() const
{
    return m_score;
}


void Enemy::explode()
{
    Vart::removeThis();
}

