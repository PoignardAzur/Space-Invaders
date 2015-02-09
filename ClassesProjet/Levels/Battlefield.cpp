

#include "Battlefield.h"


Battlefield::Battlefield(PlayerShip* player, sf::FloatRect visibleZone)
{
    setPlayer(player);
    setVisibleZone(visibleZone);
}

Battlefield::Battlefield(sf::FloatRect visibleZone)
{
    setVisibleZone(visibleZone);
}


void Battlefield::setPlayer(PlayerShip* player)
{
    m_player.reset(player);
}

void Battlefield::setVisibleZone(sf::FloatRect visibleZone)
{
    m_visibleZone = visibleZone;
}


void Battlefield::updatePlayer(float dt)
{
    if (m_player)
    {
        m_player->update(dt);

        if (player()->doDelete())
        m_player = nullptr;
    }
}


void Battlefield::updateRedBullets(float dt)
{
    t_red_bullets.updateAll(dt);

    for (auto bullet_p : t_red_bullets)
    {
        bullet_p->recycle(m_visibleZone);

        if (! bullet_p->doDelete())
        {
            for (auto enemy_p : t_enemies)
            {
                bullet_p->testHarming(*enemy_p);
            }
        }
    }
}

void Battlefield::updateBlueBullets(float dt)
{
    t_blue_bullets.updateAll(dt);

    if (m_player)
    {
        for (auto bullet_p : t_blue_bullets)
        {
            bullet_p->testHarming(*m_player);
        }
    }
}

void Battlefield::updateEnemies(float dt)
{
    t_enemies.updateAll(dt, false);

    for (auto p = t_enemies.begin(); p != t_enemies.end(); p++)
    {
        auto& enemy_p = *p;

        if (enemy_p->isDead())
        {
            enemyDies(enemy_p);
        }

        else if (enemy_p->recycle(m_visibleZone))
        {
            if (!enemyEscapes(enemy_p))
            {
                p = t_enemies.erase(p);
                p--;
            }
        }
    }

    t_enemies.deleteDeadVarts();
}


void Battlefield::updateAll(float dt)
{
    updatePlayer(dt);
    updateEnemies(dt);
    updateRedBullets(dt);
    updateBlueBullets(dt);
}



void Battlefield::drawAllIn(AbstractDrawer& fenetre)
{
    t_blue_bullets.drawAllIn(fenetre);
    t_red_bullets.drawAllIn(fenetre);
    t_enemies.drawAllIn(fenetre);

    if (m_player)
    m_player->drawIn(fenetre);
}


PlayerShip* Battlefield::player()
{
    return m_player.get();
}

const PlayerShip* Battlefield::player() const
{
    return m_player.get();
}


void Battlefield::killAllEnemies(bool explode, bool scorePoints)
{
    for (auto enemy_p : t_enemies)
    {
        enemy_p->kill(explode, scorePoints);
    }
}

void Battlefield::deleteFriendlyShots()
{
    t_red_bullets.clear();
}

void Battlefield::deleteEnemyShots()
{
    t_blue_bullets.clear();
}


VartArray<Enemy>* Battlefield::enemies()
{
    return &t_enemies;
}

VartArray<Bullet>* Battlefield::redBullets()
{
    return &t_red_bullets;
}

VartArray<Bullet>* Battlefield::blueBullets()
{
    return &t_blue_bullets;
}











