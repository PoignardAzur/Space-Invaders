
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

    Battlefield(PlayerShip* player = nullptr, sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0));
    Battlefield(sf::FloatRect visibleZone);
    virtual void setVisibleZone(sf::FloatRect visibleZone);

    void updateAll(float dt);
    void drawAllIn(AbstractDrawer& fenetre);


    protected :

    PlayerShip* player();
    const PlayerShip* player() const;
    virtual void setPlayer(PlayerShip* player);

    virtual bool enemyEscapes(std::shared_ptr<Enemy>& e) = 0;
    virtual void enemyDies(std::shared_ptr<Enemy>& e) = 0;

    void killAllEnemies(bool explode = true, bool scorePoints = true);
    void deleteFriendlyShots();
    void deleteEnemyShots();

    void updatePlayer(float dt);
    void updateRedBullets(float dt);
    void updateBlueBullets(float dt);
    void updateEnemies(float dt);

    VartPusher<Enemy>* enemies();
    VartPusher<Bullet>* redBullets();
    VartPusher<Bullet>* blueBullets();


    private :

    std::unique_ptr<PlayerShip> m_player;

    VartArray<Enemy> t_enemies;
    VartArray<Bullet> t_red_bullets;
    VartArray<Bullet> t_blue_bullets;

    sf::FloatRect m_visibleZone;
};



#endif // BATTLEFIELD_HEADER
