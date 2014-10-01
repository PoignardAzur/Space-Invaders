


#ifndef BULLET_HEADER
#define BULLET_HEADER

#define BULLET_HITBOX sf::FloatRect(-4, -16, 8, 32)
#define DEFAULT_BULLET_POWER 10
#define MAX_BULLET_SPEED -900.0f
//#define BULLET_ACCELERATION 100.0f


#include "../Moteur2D.h"
#include "HurtableEntity.h"

class Enemy;
class PlayerShip;


class Bullet : public BaseVart
{
    public :

    Bullet();
    Bullet(sf::Vector2f pos, float maxSpeed, const sf::Sprite& bulletSprite);
    void set(sf::Vector2f pos, float maxSpeed, const sf::Sprite& bulletSprite);

    void update(float dt);
    void recycle(sf::FloatRect visibleZone);          // deletes the bullet once it exits that zone

    void testHarming(Enemy& e);                     // if the bullet is touching 'e', then 'e' takes up to m_power damage and the bullet loses power
    void testHarming(PlayerShip& e);


    protected :

    void testHarming(HurtableEntity& he, const PhysicObject& po);
    void decreasePower(int powerCut);

    private :
    int m_power;

//    float m_maxSpeed;
//    bool m_maxSpeedReached;
};



#endif

