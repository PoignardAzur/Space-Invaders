

#include "Gestionnaire.h"

// Fuuuuuuuuuuuuuuuuu

Gestionnaire::Gestionnaire(Niveau* niveauJoue, Entrees* tableauEntrees, sf::RenderWindow* cible)
{
    attribuer(niveauJoue, tableauEntrees, cible);
}

void Gestionnaire::attribuer(Niveau* niveauJoue, Entrees* tableauEntrees, sf::RenderWindow* cible)
{
    m_niveauJoue = boost::shared_ptr<Niveau>(niveauJoue);
    m_entrees = boost::shared_ptr<Entrees>(tableauEntrees);
    m_cible = cible;

    m_fenetre = boost::shared_ptr<AfficheurObjets>(new AfficheurObjets(cible));
    m_cible->setFramerateLimit(LIMITE_NOMBRE_FPS);
}

void Gestionnaire::MAJ()
{
    m_fenetre->effacer();
    m_niveauJoue->MAJ();
    m_niveauJoue->afficherDans(*m_fenetre);

    m_cible->display();
}

bool Gestionnaire::continuer()
{
    return ! m_niveauJoue->detruire();
}

