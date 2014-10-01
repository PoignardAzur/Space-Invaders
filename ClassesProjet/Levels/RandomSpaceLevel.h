

#ifndef RANDOM_SPACE_LEVEL_HEADER
#define RANDOM_SPACE_LEVEL_HEADER

#include "BasicSpaceLevel.h"
#include "Waves/RandomWave.h"


class RandomSpaceLevel : public BasicSpaceLevel
{
    public :

    RandomSpaceLevel(sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0));
    void setResources(const TextureList* t, const ResourceList<EnemiesStats>* statsList);


    private :

    RandomWave* m_wave;
};





#endif // RANDOM_SPACE_LEVEL_HEADER




