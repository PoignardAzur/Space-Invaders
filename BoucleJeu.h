


#ifndef HEADER_BOUCLE
#define HEADER_BOUCLE

#include "Moteur2D/includes.h"
#include "Vaisseau.h"


#define HAUTEUR_FENETRE 400
#define LARGEUR_FENETRE 600

#define ADRESSE_IMAGE_VAISSEAU "Vaisseau.bmp"
#define ADRESSE_IMAGE_ENNEMI "Ennemi.bmp"
#define ADRESSE_IMAGE_TIR "Tir.bmp"

#define POSITION_VAISSEAU sf::Vector2f(LARGEUR_FENETRE / 2 - 50, HAUTEUR_FENETRE - 100)
#define HITBOX_VAISSEAU CtB::ObjetPhysique(sf::IntRect(0,0, 110, 60), POSITION_VAISSEAU)


class BoucleJeu : public CtB::Gestionnaire
{
    public :

    BoucleJeu(CtB::AfficheurObjets* cible = 0, CtB::Entrees* nEntrees = 0);

    virtual void MAJ();
 // void finirJeu();

    private :

    CtB::Alea m_hasard;
    boost::shared_ptr<Vaisseau> m_joueur;

    sf::Texture m_imageEnnemi;
    sf::Texture m_imageTir;
    sf::Texture m_imageVaisseau;
};


#endif
