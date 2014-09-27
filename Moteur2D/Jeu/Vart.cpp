

#include "ParametresVart.h"



CtB::Vart::Vart(Parametres& para) : m_detruit(false), m_sprite(para.sprite()), m_hitbox(para.hitbox())
{

}

CtB::Vart::Vart(Parametres& para, sf::Vector2f position) : m_detruit(false), m_sprite(para.sprite()), m_hitbox(para.hitbox())
{
    m_hitbox->deplacer(position);
}

void CtB::Vart::MAJ()
{
    m_hitbox->MAJ();
}

bool CtB::Vart::detruire() const
{
    return m_detruit;
}

void CtB::Vart::afficherDans(AfficheurObjets& cible)
{
    cible.afficher(*m_sprite);
}


void CtB::Vart::detruireObjet()
{
    m_detruit = true;
}


