

#include "AfficheurObjets.h"



CtB::AfficheurObjets::AfficheurObjets(sf::RenderTarget* cible) : m_fenetreCible(cible)
{

}

void CtB::AfficheurObjets::afficher(const ObjetAffichable& objet)
{
    m_fenetreCible->draw(objet.sprite());
}

void CtB::AfficheurObjets::afficher(const ObjetAffichable& objet, const ParametresAffichage& para)
{
    m_fenetreCible->draw(objet.sprite());
}


