


#include "Fusil.h"



ParametresFusil::ParametresFusil(std::istream& flux)
{
    attribuer(flux);
}

ParametresFusil::ParametresFusil()
{

}

void ParametresFusil::attribuer(std::istream& flux)
{
    flux >> cadenceTir;
    flux >> munitionsMax;
    flux >> munitions;
    flux >> vitesseCharge;
}


Fusil::Fusil(const ParametresLaser& para, const ParaVart& paraobjet, const ParametresFusil& paraFusil)
{
    attribuer(para, paraobjet, paraFusil);
}


void Fusil::attribuer(const ParametresLaser& para, const ParaVart& paraobjet, const ParametresFusil& paraFusil)
{
    m_paraFusil = paraFusil;
    m_tempsDepuisDernierTir = paraFusil.cadenceTir;

    m_paraobjet = paraobjet;
    m_paraTir = para;
}


void Fusil::attribuer(TableauVart<Tir>& ncible)
{
    Emetteur<Tir>::attribuer(ncible);
}


void Fusil::MAJ()
{
    m_tempsDepuisDernierTir ++;
    m_paraFusil.munitions += m_paraFusil.vitesseCharge;

    if (m_paraFusil.munitions > m_paraFusil.munitionsMax)
    m_paraFusil.munitions = m_paraFusil.munitionsMax;
}

bool Fusil::peutTirer()
{
    return (m_tempsDepuisDernierTir >= m_paraFusil.cadenceTir && m_paraFusil.munitions >= m_paraTir.munitionsConsommees);
}

void Fusil::tirer(sf::Vector2f position)
{
    if (!peutTirer())
    return;

/// else
    cible().ajouter(new Laser(m_paraTir, m_paraobjet, position));
    m_tempsDepuisDernierTir = 0;
    m_paraFusil.munitions -= m_paraTir.munitionsConsommees;
}




