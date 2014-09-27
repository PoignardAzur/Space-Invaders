

#include "BossClass.h"

// Fuuuuuuuuuuuuuuuuu

BlossClass::BlossClass(Level* niveauJoue, Inputs* tableauEntrees, sf::RenderWindow* cible)
{
    set(niveauJoue, tableauEntrees, cible);
}

void BlossClass::set(Level* niveauJoue, Inputs* tableauEntrees, sf::RenderWindow* cible)
{
    m_niveauJoue = boost::shared_ptr<Level>(niveauJoue);
    m_entrees = boost::shared_ptr<Inputs>(tableauEntrees);
    m_cible = cible;

    if (cible)
    m_fenetre = boost::shared_ptr<AbstractDrawer>(new ObjectDrawer(cible));
    else
    m_fenetre = boost::shared_ptr<VoidDrawer>();
//    m_fenetre = boost::shared_ptr<AfficheurObjetsAbstrait>(new AfficheurObjetsAbstrait);
}

void BlossClass::update(float tickSize)
{
    m_fenetre->clear();
    m_niveauJoue->update(tickSize);
    m_niveauJoue->drawIn(*m_fenetre);

    if (m_cible)
    m_cible->display();
    m_entrees->update();
}

Inputs* BlossClass::windowInputs()
{
    return m_entrees.get();
}

Level* BlossClass::playedLevel()
{
    return m_niveauJoue.get();
}


bool BlossClass::doContinue()
{
    return (! m_niveauJoue->deleteLevel()) && (! windowInputs()->endGame());
}

