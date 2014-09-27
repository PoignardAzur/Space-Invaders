


#include "Ship.h"



Ship::Ship()
{

}

Ship::Ship(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesseY, float accelerationY)
{
    define(vie, spr, hitbox, nPosition, vitesseY, accelerationY);
}

void Ship::define(Sprite* spr, sf::IntRect hitbox, Para parameters)
{
    define(parameters.life, spr, hitbox, parameters.position, parameters.ySpeed, parameters.yAcceleration);
}

void Ship::define(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesse, float acceleration)//.99999
{
    m_life = vie;
    setSprite(spr);
    setHitbox(PhysicObject( hitbox, nPosition, sf::Vector2f(0,vitesse), sf::Vector2f(0,acceleration) ));
}


void Ship::getDamages(int amount)
{
	if (life() <= 0)
	return;

/// else
	setLife(life()-amount);

	if (life() <= 0)
;//	explode();
}

void Ship::explode()
{
    Vart::removeThis();
//	tableauExplosion.ajouterExplosion(TODO);
}

int Ship::life()
{
	return m_life;
}

void Ship::setLife(int amount)
{
	m_life = amount;
}

