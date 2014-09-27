



#ifndef SHIP_HEADER
#define SHIP_HEADER

#include "../Moteur2D.h"


class Ship : public Vart
{
	public :

	struct Para;

	Ship();
	Ship(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesseY, float accelerationY);
	void define(Sprite* spr, sf::IntRect hitbox, Para parameters);
	void define(int vie, Sprite* spr, sf::IntRect hitbox, sf::Vector2f nPosition, float vitesse, float acceleration);//.99999

	void getDamages(int amount);
	virtual void explode();

	protected :
	int life();
	void setLife(int amount);

	private :

	int m_life;
//    TableauExplosions* m_tableauExplosions; //use-a


    public :

	struct Para
	{
	    int life;
	    sf::Vector2f position;
	    float ySpeed;
        float yAcceleration;

        Para(int vie, sf::Vector2f nPosition, float vitesseY, float accelerationY) :
        life(vie), position(nPosition), ySpeed(vitesseY), yAcceleration(accelerationY)
        { }
	};
};



#endif


