

#include "BoucleJeu.h"


BoucleJeu::BoucleJeu(Inputs* tableauEntrees, sf::RenderWindow* cible) :
m_level(new LoadingSpaceLevel), m_textureDrawer(&m_mainTexture), m_deathTimer(TIME_BEFORE_RESPAWN)
{
    m_mainTexture.create(LARGEUR_FENETRE, HAUTEUR_FENETRE - HAUTEUR_HUD);
    m_window = cible;
    set(tableauEntrees, cible);

    m_level->set(sf::IntRect(0,0, LARGEUR_FENETRE, HAUTEUR_FENETRE), sf::IntRect(0, HAUTEUR_SPAWN, LARGEUR_FENETRE, 10));

    sql3::Database db;
    std::ifstream file(COMMAND_FILE);

    if (file.is_open())
    {
        db.createFromFile(file, MAIN_DATABASE);
    }

    else
    {
        db.open(MAIN_DATABASE);
    }

    m_level->setTexturesFromFiles(db);
    m_level->setEnemiesFromFile(db);
    m_level->setWavesFromFile(db);

    if (!tex_player_life.loadFromFile("Ressources\\Images\\Vie.bmp"))
    throw "The idle texture could not be charged";

    if (!tex_player_idle.loadFromFile("Ressources\\Images\\Vaisseau_Joueur.bmp"))
    throw "The idle texture could not be charged";

    if (!tex_player_shoot.loadFromFile("Ressources\\Images\\Vaisseau_Joueur_Charge.bmp"))
    throw "The shooter texture could not be charged";

    if (!tex_player_bullet.loadFromFile("Ressources\\Images\\Tir.bmp"))
    throw "The bullet texture could not be charged";

    m_lifes = 3;
    setPlayer();

    m_interface.setLifeSprite(sf::Sprite(tex_player_life));
    m_interface.setScoreCounter(DEFAULT_FONT_NAME, sf::Color::White);
}


void BoucleJeu::setPlayer()
{
    m_player = boost::shared_ptr<PlayerShip>(new PlayerShip(windowInputs()));

    m_player->set( new Sprite(sf::Sprite(tex_player_idle)), new Sprite(sf::Sprite(tex_player_shoot)) );
    m_player->setBullets(sf::Sprite(tex_player_bullet));

    m_level->set(m_player.get());
}


Level<float, SpaceStats>* BoucleJeu::playedLevel()
{
    return m_level.get();
}

bool BoucleJeu::doContinue()
{
    return ( m_level->outputData().continuePlaying && ! windowInputs()->endGame() );
}

int BoucleJeu::finalScore()
{
    return m_score;
}


void BoucleJeu::update(float tickSize)
{
    m_textureDrawer.clear();
    m_window->clear(sf::Color(128, 128, 128));

    playedLevel()->update(tickSize);
    playedLevel()->drawIn(m_textureDrawer);

    sf::Sprite spr(m_mainTexture.getTexture());
    spr.setPosition(sf::Vector2f(0, HAUTEUR_FENETRE));
    spr.setScale(1, -1);
    renderingWindow()->draw(Sprite(spr));
    windowInputs()->update();

    m_score = m_level->outputData().score;


    if (m_player)
    {
        if (m_player->doDelete())
        {
            m_player.reset();

            if (!m_lifes)
            m_level->gameOver();
        }

    }

    else if (m_lifes && m_deathTimer.decrement(tickSize))
    {
        m_lifes--;
        setPlayer();
        m_deathTimer.resetTimeToMax();
    }

    m_interface.setRemainingLives(m_lifes);
    m_interface.setScore(m_score);
    m_interface.drawIn(*m_window);

}

