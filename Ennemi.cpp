

#include "Ennemi.h"


Ennemi::Ennemi(const ParaVart& paraobjet, sf::Vector2f position, Arme<Tir>* arme) : m_arme(arme), Vart(paraobjet, position)
{

}

void Ennemi::MAJ()
{
    Vart::MAJ();

    if (!m_arme)
    return;

/// else
    m_arme->tirer(position());
    m_arme->MAJ();
}


