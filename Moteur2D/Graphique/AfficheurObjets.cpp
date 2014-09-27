

#include "AfficheurObjets.h"



AfficheurObjets::AfficheurObjets(sf::RenderTarget* cible) : m_fenetreCible(cible)
{

}

void AfficheurObjets::afficher(const ObjetAffichable& objet)
{
    m_fenetreCible->draw(objet.afficher());
}

void AfficheurObjets::effacer()
{
    m_fenetreCible->clear();
}



