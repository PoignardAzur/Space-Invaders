

#include "RandomSpaceLevel.h"


RandomSpaceLevel::RandomSpaceLevel(sf::FloatRect visibleZone) : BasicSpaceLevel(visibleZone)
{
    m_wave.setLevel(this);
    m_wave.setRNG(&rng());
    m_wave.setBulletArray(blueBullets());
}


void RandomSpaceLevel::generateEnemyWaves(float dt)
{
    m_wave.update(dt);
}


void RandomSpaceLevel::setResources(const TextureList* t, const ResourceList<EnemiesStats>* statsList)
{
    m_wave.setResources(t, statsList);
}




