

#ifndef RANDOM_WAVE_HEADER
#define RANDOM_WAVE_HEADER

#include "RandomEnemyPlacer.h"


class RandomWave : public RandomEnemyPlacer
{
    public :

    RandomWave(std::default_random_engine* rng = nullptr, TextureList* textureList = nullptr, ResourceList<EnemiesStats>* stats = nullptr);
    void setRNG(std::default_random_engine* rng);
    void setDelay(float min, float max);

    virtual bool update(float dt);
    virtual bool isDone() const;


    private :

    std::default_random_engine* m_rng;

    Timer m_timer;
    float m_minDelay;
    float m_maxDelay;
    bool m_firstTime;
};


#endif // RANDOM_WAVE_HEADER

