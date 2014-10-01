

#include "RandomSpaceLevel.h"


RandomSpaceLevel::RandomSpaceLevel(sf::FloatRect visibleZone) : BasicSpaceLevel(visibleZone)
{
    m_wave = new RandomWave();

    m_wave->setRNG(&rng());
    m_wave->setBulletArray(blueBullets());

    BasicSpaceLevel::addWave(m_wave);
}


void RandomSpaceLevel::setResources(const TextureList* t, const ResourceList<EnemiesStats>* statsList)
{
    m_wave->setResources(t, statsList);
}




