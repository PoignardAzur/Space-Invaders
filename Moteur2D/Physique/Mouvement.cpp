
#include "Mouvement.h"




CtB::Mouvement::Mouvement(sf::Vector2f position, sf::Vector2f vitesse) : m_position(position), m_vitesse(vitesse)
{

}

void CtB::Mouvement::MAJ()
{
    deplacer(m_vitesse, true);
}

void CtB::Mouvement::changerVitesse(sf::Vector2f nvitesse, bool relatif)
{
    if (relatif)
    m_vitesse += nvitesse;

    else
    m_vitesse = nvitesse;
}

void CtB::Mouvement::deplacer(sf::Vector2f nposition, bool relatif)
{
    if (relatif)
    m_position += nposition;

    else
    m_position = nposition;
}

sf::Vector2f CtB::Mouvement::position() const
{
    return m_position;
}

sf::Vector2f CtB::Mouvement::vitesse() const
{
    return m_vitesse;
}

