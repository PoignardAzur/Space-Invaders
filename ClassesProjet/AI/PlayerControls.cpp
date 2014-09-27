

#include "PlayerControls.h"


PlayerControls::PlayerControls(Inputs* nInput)
{
    setInputs(nInput);
}

void PlayerControls::setInputs(Inputs* nInput)
{
    m_inputs = nInput;
}

char PlayerControls::goLeftRight()
{
    if (m_inputs->keyboardButtons()[GO_LEFT_KEY] && !m_inputs->keyboardButtons()[GO_RIGHT_KEY])
    return -1;

    if (!m_inputs->keyboardButtons()[GO_LEFT_KEY] && m_inputs->keyboardButtons()[GO_RIGHT_KEY])
    return 1;

/// else
    return 0;
}

char PlayerControls::startStopBoost()
{
    if (m_inputs->keyboardButtons()[BOOST_KEY] == Pressee)
    return 1;

    if (m_inputs->keyboardButtons()[BOOST_KEY] == Lachee)
    return -1;

/// else
    return 0;
}

bool PlayerControls::doShoot(const Vart& target, const sf::Vector2f shootFrom)
{
    return m_inputs->keyboardButtons()[SHOOT_KEY];
}

