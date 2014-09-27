

#include "RandomSpaceLevel.h"


#define MIN_TIME_FIRST_SPAWN 0
#define MAX_TIME_FIRST_SPAWN MIN_TIME_FIRST_SPAWN

#define MIN_DELAY_BETWEEN_SPAWN 1.0
#define MAX_DELAY_BETWEEN_SPAWN MIN_DELAY_BETWEEN_SPAWN + 1.0




RandomSpaceLevel::RandomSpaceLevel(unsigned int seed, PlayerShip* player, sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
BasicSpaceLevel(seed, player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight)
{
    build();
}

RandomSpaceLevel::RandomSpaceLevel(std::seed_seq& seed, PlayerShip* player, sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
BasicSpaceLevel(seed, player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight)
{
}

void RandomSpaceLevel::build()
{
    std::uniform_real_distribution<float> timeBeforeSpawn(MIN_TIME_FIRST_SPAWN, MAX_TIME_FIRST_SPAWN);
    m_timer.setTime(timeBeforeSpawn(randomGenerator()));

    m_minDelay = MIN_DELAY_BETWEEN_SPAWN;
    m_maxDelay = MAX_DELAY_BETWEEN_SPAWN;
}



void RandomSpaceLevel::generateEnemyWaves(float tickSize)
{
    if (m_timer.decrement(tickSize))
    {
        std::uniform_real_distribution<float> timeBeforeNext(m_minDelay, m_maxDelay);

        createEnemy();
        m_timer.setTime(timeBeforeNext( randomGenerator() ));
    }

    // Enemy spawns get closer at the player's survival time augments

    if (m_minDelay > 0.2f)
    m_minDelay -= (1.0f / 100) * tickSize;

    if (m_maxDelay > 0.5f)
    m_maxDelay -= (1.0f / 200) * tickSize;
}

void RandomSpaceLevel::createEnemy()
{
    std::uniform_int_distribution<int> p(0, m_names.size() - 1);
    const std::string& name = m_names[p(randomGenerator())];

    generateEnemy(name);
}


void RandomSpaceLevel::setNames(const std::vector<std::string>& names)
{
    m_names = names;
}






