

#include "Enemy.h"
#include <cassert>


Enemy::Enemy()
{

}


Enemy::Enemy(const sf::Sprite& sprite, sf::FloatRect hitbox, float nSpeed, int hp, int nScore)
{
    set(sprite, hitbox, nSpeed, hp, nScore);
}


void Enemy::set(const sf::Sprite& sprite, sf::FloatRect hitbox, float nSpeed, int hp, int nScore)
{
    m_has_entered = false;

    setHitbox(PhysicObject(hitbox));
    BaseVart::setSprite(sprite);
    BaseVart::PhysicObject::changeSpeed(sf::Vector2f(0, nSpeed));

    m_hp = hp;
    m_score = nScore;
}

void Enemy::setHitbox(const PhysicObject& hitbox)
{
    BaseVart::PhysicObject::set(hitbox);
}

bool Enemy::recycle(const sf::FloatRect& visibleZone)
{
    if (testCollision(BaseVart::PhysicObject::placedBox(), visibleZone))
    {
        m_has_entered = true;
    }

    else if (m_has_entered)
    {
        BaseVart::removeThis();
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
        kill(true, true);
        dm = m_hp;
        m_hp = 0;
    }

    return dm;
}

void Enemy::kill(bool doExplode, bool givePoints)
{
    if (!givePoints)
    m_score = 0;

    if (doExplode)
    explode();

    BaseVart::removeThis();
}


bool Enemy::isDead() const
{
    return BaseVart::doDelete();
}

int Enemy::score() const
{
    return m_score;
}


void Enemy::explode()
{
    /// TODO
}

Enemy::~Enemy()
{

}

