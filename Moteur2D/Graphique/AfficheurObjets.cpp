

#include "AfficheurObjets.h"



CtB::AfficheurObjets::AfficheurObjets(sf::RenderWindow* cible) : m_fenetreCible(cible)
{
    m_fenetreCible->setFramerateLimit(LIMITE_NOMBRE_FPS);
}

void CtB::AfficheurObjets::afficher(const ObjetAffichable& objet)
{
    m_fenetreCible->draw(objet.afficher());
}

void CtB::AfficheurObjets::effacer()
{
    m_fenetreCible->clear();
}


void CtB::AfficheurObjets::afficherTout()
{
    m_fenetreCible->display();
}


