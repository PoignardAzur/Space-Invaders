
#ifndef SOURCE_VARTS
#define SOURCE_VARTS


#ifndef HEADER_VARTS
#include "ParametresVart.h"
#endif





CtB::Vart::Vart(const ParaVart& para) :
m_detruit(false), m_sprite(new Sprite( para.sprite() )), m_hitbox(new ObjetPhysique( para.hitbox() ))
{

}


CtB::Vart::Vart() : m_detruit(false)
{

}


CtB::Vart::Vart(const ParaVart& para, sf::Vector2f position) :
m_sprite(new Sprite( para.sprite() )), m_hitbox(new ObjetPhysique( para.hitbox() ))
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
    m_sprite->deplacer(m_hitbox->position());
    cible.afficher(*m_sprite);
}



void CtB::Vart::detruireObjet()
{
    m_detruit = true;
}




void CtB::Vart::attribuer(const ParaVart& para)
{
    m_sprite = boost::shared_ptr<Sprite>( new Sprite( para.sprite() ));
    m_hitbox = boost::shared_ptr<ObjetPhysique>( new ObjetPhysique( para.hitbox() ));
}


void CtB::Vart::attribuer(Sprite* para)
{
    m_sprite = boost::shared_ptr<Sprite>(para);
}


void CtB::Vart::attribuer(ObjetPhysique* para)
{
    m_hitbox = boost::shared_ptr<ObjetPhysique>(para);
}


#endif


