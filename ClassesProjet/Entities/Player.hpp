



#ifndef PLAYER_SHIP_HEADER
#define PLAYER_SHIP_HEADER

#include "Ship.h"
#include "Straffer.h"
#include "Shooter.h"

#include "../AI/PlayerControls.h"
#include "../BulletEmitter.h"


class PlayerShip : public Ship, public Straffer, public Shooter
{
    public :

	PlayerShip() { }
	PlayerShip(Sprite* spr, sf::IntRect hitbox, Inputs* in, BulletEmitter* weapon, Ship::Para, const Straffer::Para&, float nAmmo, float nMaxAmmo);
    void set(Sprite* spr, sf::IntRect hitbox, Inputs* in, BulletEmitter* weapon, Ship::Para parameters, const Straffer::Para&, float nAmmo, float nMaxAmmo);

    void update(float ticks);


    protected :

	void moveLR(float ticks);
	float leftPos();
	float rightPos();


    private :

    PlayerControls m_controls;
    boost::shared_ptr<BulletEmitter> m_weapon;
};



#endif


