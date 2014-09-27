


#include "ShooterAI.h"



ShooterAI::ShooterAI(int brainLevel)
{
    m_brainLevel = brainLevel;
}

bool ShooterAI::doShoot(const Vart& target, const sf::Vector2f shootFrom)
{
    return target.relativeBox().contains(sf::Vector2i(static_cast<int>(shootFrom.x), target.relativeBox().top));
}

