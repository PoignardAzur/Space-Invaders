

#ifndef WEAPON_HEADER
#define WEAPON_HEADER

#define TIME_TO_FIRST_SHOOT 0.5
#define ENEMY_COOLDOWN 1.5

#include "Bullet.h"

class Weapon
{
    public :

    explicit Weapon(float shootCoolDown = ENEMY_COOLDOWN, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    explicit Weapon(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray = nullptr);
    Weapon(const Weapon& otherWeapon);
    virtual ~Weapon() {}

    void setStats(float shootCoolDown, float timeToNextShoot = TIME_TO_FIRST_SHOOT);
    void setBulletSprite(const sf::Sprite& bulletSpr);
    void setBulletArray(VartArray<Bullet>* bulletArray);
    void setBullets(const sf::Sprite& bulletSpr, VartArray<Bullet>* bulletArray);

    bool update(float tickSize);
    bool readyToShoot() const;
    virtual bool tryToShoot(const sf::Vector2f& bulletPos, float bulletSpeed = MAX_BULLET_SPEED);
    int ammo() const;


    protected :

    virtual void shoot(const sf::Vector2f& bulletPos, float bulletSpeed);
    void setAmmoCount(int a, bool relative = false);


    private :

    Timer m_timer;
    sf::Vector2f m_bulletCenter;
    int m_ammo;                                 // negative numbers mean infinite ammo

    sf::Sprite m_bulletSprite;
    VartArray<Bullet>* p_bulletArray;           // use-a
};



#endif
