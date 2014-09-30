


#ifndef SHOOTING_ENEMY_HEADER
#define SHOOTING_ENEMY_HEADER


#include "..\Weaponry\Weapon.h"
#include "Enemy.h"


class ShootingEnemy : public Enemy
{
    public :

    ShootingEnemy();
    explicit ShootingEnemy(const Weapon& w);
    virtual ~ShootingEnemy() {}

    void setBullets(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray);
    void setStats(float shootCoolDown, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    //void setWeapon(const Weapon& w);
    void update(float dt);

    protected :
    virtual void setHitbox(const PhysicObject&); // sets the center

    private :

    sf::Vector2f m_center;
    Weapon m_weapon;
};




#endif


