
#ifndef BATTLEFIELD_HEADER
#define BATTLEFIELD_HEADER

#define DEFAULT_SPAWN_HEIGHT 0

#include "../PlayerShip.h"
#include "../Enemies/ShootingEnemy.h"
#include "../Enemies/EnemiesStats.h"
#include <utility>


class Battlefield
{
    public :

    Battlefield(PlayerShip* player = nullptr, sf::IntRect visibleZone = sf::IntRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);
    Battlefield(sf::IntRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight = DEFAULT_SPAWN_HEIGHT, PlayerShip* player = nullptr);

    virtual void setPlayer(PlayerShip* player);
    virtual void setZones(sf::IntRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight = DEFAULT_SPAWN_HEIGHT);

    void updateAll(float tickSize);
    void drawAllIn(AbstractDrawer& fenetre);


    protected :

    void add(Enemy* e);
    void placeInBounds(Enemy& e, std::default_random_engine& randomGenerator);
    void placeInBounds(Enemy& e, std::default_random_engine& randomGenerator, float x_min, float x_max);
    void placeInBounds(Enemy& e, std::default_random_engine& randomGenerator, float x_min, float x_max, float y);
    void placeAtPosition(Enemy& e, float x, float y);

//    Enemy* generateBasicEnemyFrom(const EnemiesStats& stats, const sf::Texture* texture_enemies);
//    ShootingEnemy* generateShootingEnemyFrom(const EnemiesStats& stats, const sf::Texture* texture_enemies, const sf::Texture* texture_enemyBullets);
    void generateFromStats(const EnemiesStats& stats, std::default_random_engine& randomGenerator, const sf::Texture* texture_enemies, const sf::Texture* texture_enemyBullets = nullptr);

    void givePlayer(Weapon* w);
    PlayerShip* player();
    const PlayerShip* player() const;

    virtual bool enemyEscapes(std::shared_ptr<Enemy>& e) = 0;
    virtual void enemyDies(std::shared_ptr<Enemy>& e) = 0;

    void killAllEnemies(bool explode = true, bool scorePoints = true);
    void deleteFriendlyShots();
    void deleteEnemyShots();

    void updatePlayer(float tickSize);
    void updateRedBullets(float tickSize);
    void updateBlueBullets(float tickSize);
    void updateEnemies(float tickSize);

    void drawEnemiesIn(AbstractDrawer& fenetre);
    void drawBlueShotsIn(AbstractDrawer& fenetre);
    void drawRedShotsIn(AbstractDrawer& fenetre);
    void drawPlayerIn(AbstractDrawer& fenetre);


    private :

    std::unique_ptr<PlayerShip> m_player;

    VartArray<Enemy> t_enemies;
    VartArray<Bullet> t_red_bullets;
    VartArray<Bullet> t_blue_bullets;

    sf::IntRect m_visibleZone;
    float m_leftSpawnLimit;
    float m_rightSpawnLimit;
    float m_spawnHeight;
};



#endif // BATTLEFIELD_HEADER
