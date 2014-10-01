

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

void RandomEnemyPlacer::setStatsWeights(const std::map<std::string, int>& statsWeights)
{
    m_statsWeights = statsWeights;
    m_totalWeight = 0;

    for (const auto& weight : m_statsWeights)
    {
        m_totalWeight += weight.second;
    }

    if (!m_totalWeight)
    {
        for (auto& weight : m_statsWeights)
        {
            m_totalWeight ++;
            weight.second ++;
        }
    }
}

void RandomEnemyPlacer::setStatsWeights(const std::vector<std::string>& stats, const std::vector<int>& weights)
{
    std::map<std::string, int> statsWeights;

    for (size_t i = 0; i < stats.size(); i++)
    {
        if (statsWeights.find(stats[i]) == statsWeights.end())
        statsWeights[stats[i]] = 0;

        if (i < weights.size())
        {
            statsWeights[stats[i]] += weights[i];
        }
    }

    setStatsWeights(statsWeights);
}



void RandomEnemyPlacer::placeEnemy(std::default_random_engine* rng)
{
    if (m_statsWeights.empty())
    {
        std::map<std::string, int> statsWeights;

        for (const auto& stat : m_stats->list())
        {
            statsWeights[stat.first] = 1;
        }

        setStatsWeights(statsWeights);
    }

    std::uniform_int_distribution<int> selectedEnemy(0, m_totalWeight);
    int i = selectedEnemy(*rng);
    auto p = m_statsWeights.begin();

    while (i > p->second)
    {
        i -= p->second;
        p ++;
    }

    placeEnemy(p->first, rng);
}


void RandomEnemyPlacer::placeEnemy(const std::string& name, std::default_random_engine* rng)
{
    const char* name2 = name.c_str();
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
    target()->add(newEnemy);
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















