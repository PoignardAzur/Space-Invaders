


#ifndef HEADER_BOUCLE
#define HEADER_BOUCLE

#include "Moteur2D.h"
#include "LoadingSpaceLevel.h"
#include <fstream>
#include "MainDimensions.h"
#include "GameInterface.h"

#define TITRE_FENETRE "Space !"
#define FRAMERATE 60
#define FRAME_SIZE (1.0f / FRAMERATE) * 2

#define MAIN_DATABASE "Ressources\\DatabaseFile.txt"
#define COMMAND_FILE  "Ressources\\CommandFile.txt"



class BoucleJeu : public BlossClass<float, SpaceStats>
{
    public :

    BoucleJeu(Inputs* tableauEntrees = 0, sf::RenderWindow* cible = 0);

    virtual void update(float tickSize);
    virtual Level<float, SpaceStats>* playedLevel();
    bool doContinue();
    int finalScore();


    private :

    GameInterface m_interface;
    ObjectDrawer m_textureDrawer;
    sf::RenderTexture m_mainTexture;
    sf::RenderWindow* m_window;

    boost::shared_ptr<PlayerShip> m_player; // has-a
    boost::shared_ptr<LoadingSpaceLevel> m_level; // has-a
    void setPlayer();

    sf::Texture tex_player_life;
    sf::Texture tex_player_idle;
    sf::Texture tex_player_shoot;
    sf::Texture tex_player_bullet;

    int m_score;
    int m_lifes;

    Timer m_deathTimer;
};


#endif
