

#include "BoucleJeu.h"


BoucleJeu::BoucleJeu(Level* a_niveauJoue, Inputs* tableauEntrees, sf::RenderWindow* cible) : BlossClass(a_niveauJoue, tableauEntrees, cible)
{
    m_niveauJoue = a_niveauJoue;

    if (! m_texture_1.loadFromFile(ADRESSE_IMAGE_VAISSEAU) )
    throw "Impossible d'ouvrir l'image a l'adresse" ADRESSE_IMAGE_VAISSEAU;
    sf::Sprite* imageVaisseau = new sf::Sprite(m_texture_1);
    Sprite* spriteVaisseau = new Sprite(imageVaisseau, imageVaisseau);


    if (! m_texture_2.loadFromFile(ADRESSE_IMAGE_TIR) )
    throw "Impossible d'ouvrir l'image a l'adresse" ADRESSE_IMAGE_TIR;
    SpriteCreator* spriteCreator = new SpriteCreator(&m_texture_2);
    BulletEmitter* weapon = new BulletEmitter(spriteCreator, HITBOX_TIR, VITESSE_TIR);

	m_ship = new PlayerShip(spriteVaisseau, HITBOX_VAISSEAU, tableauEntrees, weapon, CARACS_1_VAISSEAU_JOUEUR, CARACS_2_VAISSEAU_JOUEUR, 0.0f, MUNITIONS_MAX_JOUEURS);
	m_niveauJoue->add(m_ship);
}

void BoucleJeu::updateGame(float tickSize)
{
    /*

    Trucs

    */
}

