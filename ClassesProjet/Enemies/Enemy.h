



#ifndef ENEMY_HEADER
#define ENEMY_HEADER

//#define DEFAULT_ENEMY_SPEED 200

#include "../Weaponry/Bullet.h"


class Enemy : public Vart, public HurtableEntity
{
    public :

    Enemy();
    Enemy(sf::IntRect spawnZone, Alea& dice, Sprite* spr, sf::IntRect hitbox, float nSpeed, int hp, int nScore);
    void set(sf::IntRect spawnZone, Alea& dice, Sprite* spr, sf::IntRect hitbox, float nSpeed, int hp, int nScore);

    int takeDamage(int dm);
    int score() const;
    bool isDead() const;
    bool recycle(const sf::IntRect& visibleZone);

    protected :
    virtual void setHitbox(const PhysicObject&); // makes the function virtual
    void explode();

    private :

    int m_hp;
    int m_score;
    bool m_has_entered;
};



#endif
