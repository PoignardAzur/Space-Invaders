

#ifndef WEAPON_HEADER
#define WEAPON_HEADER

#define TIME_TO_FIRST_SHOOT 0.5
#define ENEMY_COOLDOWN 1.5

#include "Bullet.h"

class Weapon
{
    public :

    Weapon(float shootCoolDown = ENEMY_COOLDOWN, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    Weapon(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray = 0);
    Weapon(const Weapon& otherWeapon);

    void set(float shootCoolDown, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    void set(const sf::Sprite& bulletSpr);
    void set(VartArray<Bullet>* bulletArray);
    void set(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray);

    bool update(float tickSize);
    bool readyToShoot();
    virtual bool tryToShoot(const sf::Vector2f& pos, float speed = MAX_BULLET_SPEED);

    protected :

    virtual void shoot(const sf::Vector2f& pos, float speed);


    private :

    Timer m_timer;
    sf::Vector2f m_bulletCenter;

    sf::Sprite m_bulletSprite;
    VartArray<Bullet>* p_bulletArray;           // use-a
};



#endif
