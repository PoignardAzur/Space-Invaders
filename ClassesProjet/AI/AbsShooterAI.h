


#ifndef ABS_SHOOTER_AI_HEADER
#define ABS_SHOOTER_AI_HEADER

#include "../Moteur2D.h"


class AbstractShooterAI // : public AI ?
{
	public :

	virtual bool doShoot(const Vart& target, const sf::Vector2f shootFrom) = 0;
};




#endif


