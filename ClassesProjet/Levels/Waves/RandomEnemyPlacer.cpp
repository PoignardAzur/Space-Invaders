

#include "RandomEnemyPlacer.h"
#include "../../MainDimensions.h"

#define DEFAULT_SPAWN_HEIGHT 0
#define DEFAULT_LEFT_LIMIT 0
#define DEFAULT_RIGHT_LIMIT LARGEUR_FENETRE



RandomEnemyPlacer::RandomEnemyPlacer(const TextureList* textureList, const ResourceList<EnemiesStats>* stats)
{
    setResources(textureList, stats);
    setLimits(DEFAULT_LEFT_LIMIT, DEFAULT_RIGHT_LIMIT);
}


void RandomEnemyPlacer::setResources(const TextureList* textureList, const ResourceList<EnemiesStats>* stats)
{
    m_textureList = textureList;
    m_stats = stats;
}

void RandomEnemyPlacer::setBulletArray(VartPusher<Bullet>* blueBullets)
{
    t_blue_bullets = blueBullets;
}

void RandomEnemyPlacer::setLimits(float left, float right)
{
    m_leftLimit = left;
    m_rightLimit = right;
}


void RandomEnemyPlacer::placeEnemy(const std::string& name, std::default_random_engine* rng)
{
    const EnemiesStats& stats = (*m_stats)[name];
    const sf::Texture& texture = (*m_textureList)[DEFAULT_ENEMY_SHOT_NAME];

    Enemy* newEnemy;

    if (stats.shoots)
    {
        Weapon w(sf::Sprite(texture), t_blue_bullets);
        w.setStats(ENEMY_COOLDOWN, TIME_TO_FIRST_SHOOT);
        newEnemy = new ShootingEnemy(w);
    }

    else
    {
        newEnemy = new Enemy();
    }

    newEnemy->set(sf::Sprite((*m_textureList)[stats.spriteName]), stats.hitbox, stats.speed, stats.hp, stats.scoreValue);

    placeInBounds(*newEnemy, rng);
    spawn(newEnemy);
}


void RandomEnemyPlacer::placeInBounds(Enemy& o, std::default_random_engine* rng)
{
    float left = m_leftLimit + o.internBox().left;
    float right = m_rightLimit - (o.internBox().left + o.internBox().width);
    std::uniform_real_distribution<float> x(left, right);
    o.move(sf::Vector2f(x(*rng), DEFAULT_SPAWN_HEIGHT - o.internBox().top - o.internBox().height));
}


const ResourceList<EnemiesStats>& RandomEnemyPlacer::stats() const
{
    return *m_stats;
}















