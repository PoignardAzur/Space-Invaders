


#include "Vaisseau.h"



Vaisseau::Vaisseau(const CtB::ParaVart& paraVaisseau, const ParaTir& paraTirs, CtB::TableauVart<Tir>* tableau, int cadenceTir) :
CtB::Vart(paraVaisseau), m_paraTirs(paraTirs)
{
    m_cadence = cadenceTir;
    m_munitions = cadenceTir;
}

void Vaisseau::tirer()
{
    if (m_munitions == m_cadence)
    {
        m_munitions = 0;
        m_tableau->ajouter(new Tir(m_paraTirs, m_hitbox->position()));
    }
}


void Vaisseau::MAJ()
{
    CtB::Vart::MAJ();

    if (m_munitions < m_cadence)
    m_munitions ++;
}


void Vaisseau::deplacer(int distance, bool relatif)
{
    if (relatif)
    distance += m_hitbox->position().x;

    if (distance < LIMITE_GAUCHE)
    distance = LIMITE_GAUCHE;

    if (distance > LIMITE_DROITE)
    distance = LIMITE_DROITE;

    m_hitbox->deplacer(sf::Vector2f(distance, 0));
}


