


#include "Laser.h"


ParametresLaser::ParametresLaser()
{

}

ParametresLaser::ParametresLaser(std::istream& flux)
{
    attribuer(flux);
}

void ParametresLaser::attribuer(std::istream& flux)
{
    flux >> incremetation;
    flux >> vitesseMax;
    flux >> degats;
    flux >> munitionsConsommees;
}


Laser::Laser(const ParametresLaser& para, const ParaVart& paraobjet, sf::Vector2f position) : Tir(paraobjet, position)
{
    m_para = para;
}

float Laser::degats()
{
    return m_para.degats;
}

void Laser::MAJ()
{
    Vart::MAJ();

    if (m_para.vitesseMax > 0)
    {
        if (vitesse().y < m_para.vitesseMax)
        changerVitesse(sf::Vector2f(0, m_para.incremetation));
    }

    else if (vitesse().y > m_para.vitesseMax)
    changerVitesse(sf::Vector2f(0, m_para.incremetation));
}


