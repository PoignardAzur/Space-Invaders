


#ifndef HEADER_BOUCLE
#define HEADER_BOUCLE

#include "Moteur2D.h"
#include "Entities/Player.hpp"
#include "SpriteCreator.h"


#define HAUTEUR_FENETRE 400
#define LARGEUR_FENETRE 600

#define ADRESSE_IMAGE_VAISSEAU "Ressources/Vaisseau.bmp"
#define ADRESSE_IMAGE_TIR "Ressources/Tir.bmp"
#define HITBOX_VAISSEAU sf::IntRect(-32,-16,32,16)
#define HITBOX_TIR sf::IntRect(-4,-16,4,16)
#define VITESSE_TIR 1.0f

#define VIE_JOUEUR 100

#define POSITION_JOUEUR sf::Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE - 50)
#define CARACS_1_VAISSEAU_JOUEUR Ship::Para(VIE_JOUEUR, POSITION_JOUEUR, 0, 0)

#define MUNITIONS_MAX_JOUEURS 100.0f

#define VITESSE_BASE_JOUEUR 100.0
#define VITESSE_BOOST_JOUEUR 1.5
#define CARACS_2_VAISSEAU_JOUEUR Straffer::Para(VITESSE_BASE_JOUEUR, VITESSE_BOOST_JOUEUR, 0, LARGEUR_FENETRE)




class BoucleJeu : public BlossClass
{
    public :

    BoucleJeu(Level* niveauJoue = 0, Inputs* tableauEntrees = 0, sf::RenderWindow* cible = 0);

    virtual void updateGame(float tickSize);
 // void finirJeu();
    void update(float tickSize)
    {
        BlossClass::update(tickSize);
        updateGame(tickSize);
    }

    private :

    Alea m_hasard;
    Level* m_niveauJoue;

    PlayerShip* m_ship;
    sf::Texture m_texture_1;
    sf::Texture m_texture_2;
};


#endif
