

#include "BoucleJeu.h"



BoucleJeu::BoucleJeu(CtB::AfficheurObjets* cible, CtB::Entrees* entrees) : Gestionnaire(cible, entrees)
{
    if (m_imageTir.loadFromFile(ADRESSE_IMAGE_TIR))
    { throw "Erreur : l'image de tir ne s'est pas chargée correctement"; }

    if (m_imageEnnemi.loadFromFile(ADRESSE_IMAGE_ENNEMI))
    { throw "Erreur : l'image d'ennemi ne s'est pas chargée correctement"; }

    if (m_imageVaisseau.loadFromFile(ADRESSE_IMAGE_VAISSEAU))
    { throw "Erreur : l'image de vaisseau ne s'est pas chargée correctement"; }

    m_joueur = boost::shared_ptr<Vaisseau>(new
    Vaisseau( CtB::ParaVart(CtB::pSpr(m_imageVaisseau), HITBOX_VAISSEAU), ParaTir(0.1, 0.01, ) ));
}

void BoucleJeu::MAJ()
{
    Gestionnaire::MAJ();
/*
    if(entreesFenetre().boutonsSouris()[sf::Mouse::Left] == Pressee)
    {
        ajouter(new CarreCouleur(m_hasard, entreesFenetre().curseur()));
    }*/
}

