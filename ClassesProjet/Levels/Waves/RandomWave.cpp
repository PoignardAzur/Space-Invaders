

#include "RandomWave.h"


#define MIN_TIME_FIRST_SPAWN 0
#define MAX_TIME_FIRST_SPAWN MIN_TIME_FIRST_SPAWN

#define MIN_DELAY_BETWEEN_SPAWN 1.0
#define MAX_DELAY_BETWEEN_SPAWN MIN_DELAY_BETWEEN_SPAWN + 1.0



RandomWave::RandomWave(std::default_random_engine* rng, TextureList* textureList, ResourceList<EnemiesStats>* stats)
{
    setResources(textureList, stats);
    setRNG(rng);

    m_minDelay = MIN_DELAY_BETWEEN_SPAWN;
    m_maxDelay = MAX_DELAY_BETWEEN_SPAWN;

    m_firstTime = true;
}


void RandomWave::setRNG(std::default_random_engine* rng)
{
    m_rng = rng;
}

void RandomWave::setDelay(float min, float max)
{
    m_minDelay = min;
    m_maxDelay = max;
}


bool RandomWave::update(float dt)
{
    if (m_firstTime)
    {
        std::uniform_real_distribution<float> timeBeforeSpawn(MIN_TIME_FIRST_SPAWN, MAX_TIME_FIRST_SPAWN);
        m_timer.setTime(timeBeforeSpawn(*m_rng));
        m_firstTime = false;
    }

    if (m_timer.decrement(dt))
    {
        std::uniform_int_distribution<int> selectedEnemy(0, stats().list().size() - 1);
        int i = selectedEnemy(*m_rng);
        auto p = stats().list().begin();

        while (i)
        {
            p ++;
            i --;
        }

        placeEnemy(p->first, m_rng);

        std::uniform_real_distribution<float> timeBeforeNext(m_minDelay, m_maxDelay);
        m_timer.setTime(timeBeforeNext(*m_rng));
    }

    // Enemy spawns get closer at the player's survival time augments

    if (m_minDelay > 0.2f)
    m_minDelay -= (1.0f / 100) * dt;

    if (m_maxDelay > 0.5f)
    m_maxDelay -= (1.0f / 200) * dt;

    return false;
}

bool RandomWave::isDone() const
{
    return false; // continues making enemies FOREVER
}

