



#ifndef ENEMY_HEADER
#define ENEMY_HEADER

//#define DEFAULT_ENEMY_SPEED 200

#include <random>
#include "../Weaponry/Bullet.h"



class Enemy : public BaseVart, public HurtableEntity
{
    public :

    Enemy();
    Enemy(const sf::Sprite& sprite, sf::IntRect hitbox, float nSpeed, int hp, int nScore);
    void set(const sf::Sprite& sprite, sf::IntRect hitbox, float nSpeed, int hp, int nScore);
    virtual ~Enemy() {}

    int takeDamage(int dm);
    int score() const;
    bool isDead() const;
    bool recycle(const sf::IntRect& visibleZone);
    void kill(bool doExplode = true, bool givePoints = true);


    protected :

    virtual void setHitbox(const PhysicObject&); // inherited to make the method virtual
    void explode();                              // doesn't include removing the object


    private :

    int m_hp;
    int m_score;
    bool m_has_entered;
};



#endif
