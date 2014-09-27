

#ifndef WAVE_SPACE_LEVEL
#define WAVE_SPACE_LEVEL

#define DEFAULT_DELAY_AFTER_VICTORY

#include "BasicSpaceLevel.h"
#include <queue>


class WaveSpaceLevel : public BasicSpaceLevel
{
    public :

    WaveSpaceLevel(unsigned int seed = epoch_to_now().count(), PlayerShip* player = nullptr, sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);
    WaveSpaceLevel(std::seed_seq& seed, PlayerShip* player = nullptr, sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0), float leftSpawnLimit = 0, float rightSpawnLimit = 0, float spawnHeight = DEFAULT_SPAWN_HEIGHT);

    virtual void generateEnemyWaves(float tickSize);
    void setVictoryDelay(float d);

    struct spawnOrder;
    void addEnemy(const std::string& statsName, float delayUntilNext);
    void addEnemy(const spawnOrder& order);


    private :

    std::queue<spawnOrder> m_orders;
    Timer m_timer;

    float m_delayAfterVictory;




    public : struct spawnOrder
    {
        std::string statsName;
        float delayBeforeCreation;

        spawnOrder(const std::string& nStatsName, float nDelayBeforeCreation)
        {
            statsName = nStatsName;
            delayBeforeCreation = nDelayBeforeCreation;
        }
    };
};




#endif // WAVE_SPACE_LEVEL


