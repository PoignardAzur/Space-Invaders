

#ifndef RANDOM_SPACE_LEVEL_HEADER
#define RANDOM_SPACE_LEVEL_HEADER

#include "BasicSpaceLevel.h"


class RandomSpaceLevel : public BasicSpaceLevel
{
    public :

    RandomSpaceLevel(unsigned int seed = epoch_to_now().count(), PlayerShip* player = nullptr, sf::IntRect visibleZone = sf::IntRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);
    RandomSpaceLevel(std::seed_seq& seed, PlayerShip* player = nullptr, sf::IntRect visibleZone = sf::IntRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);

    virtual void generateEnemyWaves(float tickSize);
    void setNames(const std::vector<std::string>& names);


    private :

    Timer m_timer;
    std::vector<std::string> m_names;

    void createEnemy();
    void build();

    float m_minDelay;
    float m_maxDelay;
};





#endif // RANDOM_SPACE_LEVEL_HEADER




