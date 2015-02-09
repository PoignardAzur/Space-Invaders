


#ifndef BULLET_HEADER
#define BULLET_HEADER

#define BULLET_HITBOX sf::FloatRect(-4, -16, 8, 32)
#define DEFAULT_BULLET_POWER 10
#define MAX_BULLET_SPEED -900.0f
//#define BULLET_ACCELERATION 100.0f

#include "../../Moteur2D/Game/SimpleVart.h"
#include "HurtableEntity.h"


class SpaceShip;


class Bullet : public SimpleVart
{
    public :

    Bullet();
    Bullet(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite);
    void set(sf::Vector2f pos, float maxSpeed, AbstractDrawable* sprite);

    void update(float dt);
    bool recycle(sf::Vector2f pos, sf::FloatRect visibleZone);          // deletes the bullet once it exits that zone

    void testHarming(sf::Vector2f pos, SpaceShip& target, sf::Vector2f targetPos);
    // if the bullet is touching 'e', then 'e' takes up to m_power damage and the bullet loses power


    protected :

    void decreasePower(int powerCut);

    private :
    int m_power;

//    float m_maxSpeed;
//    bool m_maxSpeedReached;
};



#endif

