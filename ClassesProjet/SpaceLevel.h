


#ifndef SPACE_LEVEL_HEADER
#define SPACE_LEVEL_HEADER

#define TODELETE "Ressources\\Images\\Tir_Ennemi.bmp"
#include "PlayerShip.h"
#include "Enemies/ShootingEnemy.h"

#include "Enemies/EnemiesStats.h"
#include "Enemies/SpawningRates.h"
#include "SpaceStats.h"
#include <utility>


class SpaceLevel : public Level<float, SpaceStats>
{
    public :

    SpaceLevel();

    virtual void set(PlayerShip* player);
    virtual void set(sf::IntRect visibleZone, sf::IntRect spawnZone);

    virtual void update(const float& tickSize);
    virtual const SpaceStats& outputData() const;
    virtual void drawIn(AbstractDrawer& fenetre);

    void generateEnemy(EnemiesStats stats);
    void generateEnemyWave(float tickSize, bool gameOver);

    void gameOver();

    protected :

    std::vector<sf::Texture> t_enemyTextures;
    std::vector<EnemiesStats> t_enemyTypes;
//    std::vector<Weapon> t_weapons;
    std::vector< std::pair<Timer, SpawningRate> > t_spawners;
    sf::Texture m_textureEnemyBullet;

    void addEnemyScore(const Enemy& e);

    private :

    PlayerShip* m_player;
    Alea m_random;

    VartArray<Enemy> t_enemies;
    VartArray<Bullet> t_red_bullets;
    VartArray<Bullet> t_blue_bullets;

    sf::IntRect m_visibleZone;
    sf::IntRect m_spawnZone;

    SpaceStats m_outPut;
};






#endif

