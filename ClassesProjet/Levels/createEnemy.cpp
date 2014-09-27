

#include "Battlefield.h"


void Battlefield::add(Enemy* e)
{
    t_enemies.add(e);
}


void Battlefield::placeInBounds(Enemy& e, std::default_random_engine& randomGenerator)
{
    placeInBounds(e, randomGenerator, m_leftSpawnLimit, m_rightSpawnLimit, m_spawnHeight);
}

void Battlefield::placeInBounds(Enemy& e, std::default_random_engine& randomGenerator, float x_min, float x_max)
{
    placeInBounds(e, randomGenerator, x_min, x_max, m_spawnHeight);
}

void Battlefield::placeInBounds(Enemy& e, std::default_random_engine& randomGenerator, float x_min, float x_max, float y)
{
    int width = e.internBox().width;

    if (x_max - x_min < width)
    {
        placeAtPosition(e, (x_min + x_max) / 2, y);
    }

    else
    {
        std::uniform_real_distribution<float> x(x_min, x_max - width);
        placeAtPosition(e, x(randomGenerator) + width / 2, y);
    }
}

void Battlefield::placeAtPosition(Enemy& e, float x, float y)
{
    e.move(sf::Vector2f(x - e.internBox().width / 2, y), false);
}




void Battlefield::generateFromStats(const EnemiesStats& stats, std::default_random_engine& randomGenerator, const sf::Texture* texture_enemies, const sf::Texture* texture_enemyBullets)
{
    Enemy* newEnemy;

    if (stats.shoots)
    {
        Weapon w(sf::Sprite(*texture_enemyBullets), &t_blue_bullets);
        w.setStats(ENEMY_COOLDOWN, TIME_TO_FIRST_SHOOT);
        newEnemy = new ShootingEnemy(w);
    }

    else
    {
        newEnemy = new Enemy();
    }

    newEnemy->set(sf::Sprite(*texture_enemies), stats.hitbox, stats.speed, stats.hp, stats.scoreValue);

    placeInBounds(*newEnemy, randomGenerator);
    add(newEnemy);
}


/*
Enemy* Battlefield::generateBasicEnemyFrom(const EnemiesStats& stats, const sf::Texture* texture_enemies)
{

}


ShootingEnemy* Battlefield::generateShootingEnemyFrom(const EnemiesStats& stats, const sf::Texture* texture_enemies, const sf::Texture* texture_enemyBullets)
{

}
*/






