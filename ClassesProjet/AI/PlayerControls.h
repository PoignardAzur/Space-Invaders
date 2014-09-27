


#ifndef PLAYER_CONTROLS_HEADER
#define PLAYER_CONTROLS_HEADER

#include "AbsShooterAI.h"
#include "AbsStraffAI.h"

#define GO_LEFT_KEY sf::Keyboard::Left
#define GO_RIGHT_KEY sf::Keyboard::Right
#define BOOST_KEY sf::Keyboard::Space
#define SHOOT_KEY sf::Keyboard::S


class PlayerControls : public AbstractShooterAI, public AbstractStraffAI
{
	public :

    PlayerControls(Inputs* nInput = 0);
    void setInputs(Inputs* nInput);

    char goLeftRight();
    char startStopBoost();
	bool doShoot(const Vart& target, const sf::Vector2f shootFrom);

	private :

    Inputs* m_inputs;
};



#endif

