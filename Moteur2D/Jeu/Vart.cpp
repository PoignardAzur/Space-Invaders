
#ifndef SOURCE_VARTS
#define SOURCE_VARTS


#ifndef HEADER_VARTS
#include "ParametresVart.h"
#endif





Vart::Vart(const ParaVart& para) :
m_detruit(false), m_sprite(new Sprite( para.sprite() )), ObjetPhysique(para.hitbox(), sf::Vector2f(0,0), para.vitesse())
{

}

Vart::Vart(const ParaVart& para, sf::Vector2f position) :
m_sprite(new Sprite( para.sprite() )), ObjetPhysique(para.hitbox(), position, para.vitesse())
{

}


void Vart::MAJ()
{
    m_sprite->MAJ();
    ObjetPhysique::MAJ();
}


bool Vart::detruire() const
{
    return m_detruit;
}


void Vart::afficherDans(AfficheurObjets& cible)
{
    m_sprite->deplacer(position() - decalage());
    cible.afficher(*m_sprite);
}



void Vart::detruireObjet()
{
    m_detruit = true;
}



/*
void Vart::attribuer(const ParaVart& para)
{
    m_sprite = boost::shared_ptr<Sprite>( new Sprite( para.sprite() ));
}
*/

void Vart::attribuer(Sprite* para)
{
    m_sprite = boost::shared_ptr<Sprite>(para);
}


#endif


