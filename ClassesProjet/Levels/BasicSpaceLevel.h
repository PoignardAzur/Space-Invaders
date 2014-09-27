


#ifndef BASIC_SPACE_LEVEL_HEADER
#define BASIC_SPACE_LEVEL_HEADER

#define IDLE_PLAYER_TEXTURE_NAME "idle"
#define SHOOTING_PLAYER_TEXTURE_NAME "shooting"
#define PLAYER_BULLET_SPRITE_NAME "redBullet"

#include "../../Moteur2D/Interfaces/BasicArcadeLevel.h"
#include "Battlefield.h"
#include "../TextureList.h"


class BasicSpaceLevel : public Battlefield, public BasicArcadeLevel<float>
{
    public :

    BasicSpaceLevel(unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count(), PlayerShip* player = nullptr, sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);
    BasicSpaceLevel(std::seed_seq& seed, PlayerShip* player = nullptr, sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);
    virtual ~BasicSpaceLevel();

    void useTextureList(TextureList* t);
    void setStats(const std::map<std::string, EnemiesStats>& statsList);
    virtual void setZones(sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight = DEFAULT_SPAWN_HEIGHT);

    virtual void update(const float& tickSize);
    virtual void drawIn(AbstractDrawer& fenetre);

    virtual bool isPlayerAlive() const;
    virtual void respawnPlayer();
    virtual void playerKilled(bool isGameOver);     // whenever the player dies, this function is called


    protected :

    void setLimits(float leftLimit, float rightLimit);

    TextureList* textureList();
    const sf::Texture* texture(const std::string& name) const;

    void generateEnemy(const std::string& name);
    virtual void generateEnemyWaves(float tickSize) = 0;

    virtual bool enemyEscapes(std::shared_ptr<Enemy>& e);
    virtual void enemyDies(std::shared_ptr<Enemy>& e);
    void bomb(bool scorePoints = true);


    private :

    TextureList* m_textureList;                                 // use-a
    std::map<std::string, EnemiesStats> m_statsList;

    float m_leftLimit;
    float m_rightLimit;
};










#endif

