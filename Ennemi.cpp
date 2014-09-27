


#include "Ennemi.h"


Ennemi::Ennemi(const ParaEnnemi& para) : CtB::Vart(para.parametres)
{
    CtB::Vart::m_hitbox->changerVitesse(sf::Vector2f(0, para.vitesse), false);
}

Ennemi::Ennemi(const ParaEnnemi& para, sf::Vector2f position) : CtB::Vart(para.parametres, position)
{
    CtB::Vart::m_hitbox->changerVitesse(sf::Vector2f(0, para.vitesse), false);
}

void Ennemi::MAJ()
{
    if(m_vie <= 0)
    detruireObjet();
}

void Ennemi::enleverVie(int quantite)
{
    m_vie -= quantite;
}


