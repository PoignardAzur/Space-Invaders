

#ifndef RANDOM_ENEMY_PLACER
#define RANDOM_ENEMY_PLACER

#include "AbsWave.h"
#include "../../TextureList.h"
#include "../../Enemies/EnemiesStats.h"
#include "../../Weaponry/Weapon.h"


class RandomEnemyPlacer : public AbsWave
{
    public :

    RandomEnemyPlacer(const TextureList* textureList = nullptr, const ResourceList<EnemiesStats>* stats = nullptr);
    void setResources(const TextureList* textureList, const ResourceList<EnemiesStats>* stats);
    void setBulletArray(VartPusher<Bullet>* blueBullets);
    void setLimits(float left, float right);

    virtual bool update(float dt) = 0;
    virtual bool isDone() const = 0;


    protected :

    void placeEnemy(const std::string& name, std::default_random_engine* rng);
    void placeInBounds(Enemy& o, std::default_random_engine* rng);
    const ResourceList<EnemiesStats>& stats() const;

    private :

    const TextureList* m_textureList;
    const ResourceList<EnemiesStats>* m_stats;

    float m_leftLimit;
    float m_rightLimit;

    VartPusher<Bullet>* t_blue_bullets;
};



#endif // RANDOM_ENEMY_PLACER
