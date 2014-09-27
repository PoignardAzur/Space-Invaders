


#ifndef SHOOTING_ENEMY_HEADER
#define SHOOTING_ENEMY_HEADER


#include "..\Weaponry\Weapon.h"
#include "Enemy.h"


class ShootingEnemy : public Enemy
{
    public :

    ShootingEnemy();
    ShootingEnemy(const Weapon& w);
    void set(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray = 0);
    void set(float shootCoolDown, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    void update(float tickSize);

    protected :
    virtual void setHitbox(const PhysicObject&); // sets the center

    private :

    sf::Vector2f m_center;
    Weapon m_weapon;
};




#endif

