


#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Ship.h"
#define DEFAULT_MAX_SPEED 1.0f


class Enemy : public Ship
{
	public :

	Enemy();
	Enemy(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesseY, float accelerationY, float m_maxSpeed);
	void define(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesse, float acceleration, float m_maxSpeed);

    void update(float ticks);
	void move(float ticks);
	void flee();


	private :

    bool b_isEscaping;
    float m_maxSpeed;
};







#endif

