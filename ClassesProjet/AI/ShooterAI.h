


#ifndef SHOOTER_AI_HEADER
#define SHOOTER_AI_HEADER

#include "AbsShooterAI.h"
#define DEFAULT_BRAIN_LEVEL 1


class ShooterAI : public AbstractShooterAI
{
	public :

    ShooterAI(int brainLevel = DEFAULT_BRAIN_LEVEL);
	bool doShoot(const Vart& target, const sf::Vector2f shootFrom);

	private :

	int m_brainLevel;
};




#endif


