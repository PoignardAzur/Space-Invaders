


#include "Tir.h"


ParaTir::ParaTir(float nVitesseMax, float nAcceleration, const CtB::ParaVart& nParametres) : parametres(nParametres)
{
    vitesseMax = nVitesseMax;
    acceleration = nAcceleration;
}


Tir::Tir(const ParaTir& para) : CtB::Vart(para.parametres)
{
    m_vitesseMax = para.vitesseMax;
    m_acceleration = para.acceleration;
}


Tir::Tir(const ParaTir& para, sf::Vector2f position) : CtB::Vart(para.parametres, position)
{
    m_vitesseMax = para.vitesseMax;
    m_acceleration = para.acceleration;
}


void Tir::MAJ()
{
    if(CtB::Vart::m_hitbox->vitesse().y =! m_vitesseMax)
    CtB::Vart::m_hitbox->changerVitesse(sf::Vector2f(0, m_acceleration), true);
}


