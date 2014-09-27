

#include "WaveSpaceLevel.h"




WaveSpaceLevel::WaveSpaceLevel(unsigned int seed, PlayerShip* player, sf::IntRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
BasicSpaceLevel(seed, player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight)
{

}

WaveSpaceLevel::WaveSpaceLevel(std::seed_seq& seed, PlayerShip* player, sf::IntRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
BasicSpaceLevel(seed, player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight)
{

}


void WaveSpaceLevel::generateEnemyWaves(float tickSize)
{
    if (m_timer.decrement(tickSize) && m_orders.size())
    {
        while (m_orders.size() && m_orders.front().delayBeforeCreation == 0)
        {
            generateEnemy(m_orders.front().statsName);
            m_orders.pop();
        }

        if (m_orders.size())
        m_timer.setTime(m_orders.front().delayBeforeCreation);
    }
}


void WaveSpaceLevel::setVictoryDelay(float d)
{
    m_delayAfterVictory = d;
}


void WaveSpaceLevel::addEnemy(const std::string& statsName, float delayUntilNext)
{
    addEnemy(spawnOrder(statsName, delayUntilNext));
}

void WaveSpaceLevel::addEnemy(const spawnOrder& order)
{
    m_orders.push(order);

    if (m_orders.size() == 1)
    m_timer.setTime(order.delayBeforeCreation);
}





