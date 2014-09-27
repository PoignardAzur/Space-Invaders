


#ifndef BULLET_HEADER
#define BULLET_HEADER

#define BULLET_HITBOX sf::IntRect(0,0, 8, 32)
#define DEFAULT_BULLET_POWER 10
#define MAX_BULLET_SPEED -900.0f
//#define BULLET_ACCELERATION 100.0f


#include "../Moteur2D.h"
#include "HurtableEntity.h"

class Enemy;
class PlayerShip;


class Bullet : public Vart
{
    public :

    Bullet();
    Bullet(sf::Vector2f pos, float maxSpeed, Sprite* bulletSprite);
    void set(sf::Vector2f pos, float maxSpeed, Sprite* bulletSprite);

    void update(float tickSize);
    void recycle(sf::IntRect visibleZone);

    void testHarming(Enemy& e);
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

