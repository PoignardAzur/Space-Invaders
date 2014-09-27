


#include "SpaceLevel.h"
#include <cassert>


SpaceLevel::SpaceLevel()
{
    m_outPut.continuePlaying = true;
    m_outPut.score = 0;

    if (!m_textureEnemyBullet.loadFromFile( TODELETE ))
    {
        throw std::string("The shooting texture could not be charged");
    }
}

void SpaceLevel::set(PlayerShip* player)
{
    m_player = player;
    m_player->setBulletArray(&t_red_bullets);
}

void SpaceLevel::set(sf::IntRect visibleZone, sf::IntRect spawnZone)
{
    m_visibleZone = visibleZone;
    m_spawnZone = spawnZone;
}

void SpaceLevel::gameOver()
{
    m_outPut.gameOverMode = true;
}

void SpaceLevel::generateEnemy(EnemiesStats stats)
{
    Enemy* newEnemy;

    if (stats.shoots)
    {
        Weapon w(sf::Sprite(m_textureEnemyBullet), &t_blue_bullets);
        w.set(ENEMY_COOLDOWN, TIME_TO_FIRST_SHOOT);
        newEnemy = new ShootingEnemy(w);
    }

    else
    {
        newEnemy = new Enemy();
    }

    newEnemy->set(m_spawnZone, m_random, new Sprite( sf::Sprite(t_enemyTextures[stats.spriteNumber]) ), stats.hitbox, stats.speed, stats.hp, stats.scoreValue);

    t_enemies.add(newEnemy);
}


void SpaceLevel::generateEnemyWave(float tickSize, bool gameOver)
{
    if (gameOver)
    tickSize *= 2;

    for (u_short i = 0; i < t_spawners.size(); ++i)
    {
        if (t_spawners[i].first.decrement(tickSize))
        {
            generateEnemy(t_enemyTypes[t_spawners[i].second.enemyNumber]);
            t_spawners[i].first.setTime(static_cast<float>(m_random(t_spawners[i].second.min, t_spawners[i].second.max)) / 10.0, false);
        }
    }
}



void SpaceLevel::update(const float& tickSize)
{
    if (m_player)
    m_player->update(tickSize);

    t_red_bullets.updateAll(tickSize);
    t_blue_bullets.updateAll(tickSize);
    t_enemies.updateAll(tickSize);

    for(u_short i = 0; i < t_red_bullets.size(); ++i)
    {
        t_red_bullets.objectN(i)->recycle(m_visibleZone);

        for(u_short j = 0; j < t_enemies.size() && ! t_red_bullets.objectN(i)->doDelete(); ++j)
        {
            t_red_bullets.objectN(i)->testHarming( *(t_enemies.objectN(j)) );
        }
    }

    if (m_player)
    {
        for(u_short i = 0; i < t_blue_bullets.size(); ++i)
        {
            t_blue_bullets.objectN(i)->testHarming(*m_player);
        }
    }

    for(u_short i = 0; i < t_enemies.size(); ++i)
    {
        if (t_enemies.objectN(i)->isDead())
        addEnemyScore(*( t_enemies.objectN(i) ));

        else if (t_enemies.objectN(i)->recycle(m_visibleZone) && m_player)
        m_player->kill();
    }

    if (m_player)
    {
        generateEnemyWave(tickSize, false);

        if (m_player->doDelete())
        m_player = 0;
    }

    else if (m_outPut.gameOverMode)
    {
        generateEnemyWave(tickSize, true);
    }

    else
    {
        for(u_short i = 0; i < t_enemies.size(); ++i)
        {
            t_enemies.objectN(i)->recycle(sf::IntRect(0, 0, 1, LARGEUR_FENETRE));
        }
    }
}

const SpaceStats& SpaceLevel::outputData() const
{
    return m_outPut;
}

void SpaceLevel::drawIn(AbstractDrawer& fenetre)
{
    if (m_player)
    m_player->drawIn(fenetre);

    t_red_bullets.drawAllIn(fenetre);
    t_blue_bullets.drawAllIn(fenetre);
    t_enemies.drawAllIn(fenetre);
}


void SpaceLevel::addEnemyScore(const Enemy& e)
{
    m_outPut.score += e.score();
}



