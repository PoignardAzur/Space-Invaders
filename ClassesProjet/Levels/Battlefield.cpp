

#include "Battlefield.h"


Battlefield::Battlefield(PlayerShip* player, sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight)
{
    setPlayer(player);
    setZones(visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight);
}

Battlefield::Battlefield(sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight, PlayerShip* player)
{
    setPlayer(player);
    setZones(visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight);
}

void Battlefield::setPlayer(PlayerShip* player)
{
    m_player.reset(player);
}

void Battlefield::setZones(sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight)
{
    m_visibleZone = visibleZone;
    m_leftSpawnLimit = leftSpawnLimit;
    m_rightSpawnLimit = rightSpawnLimit;
    m_spawnHeight = spawnHeight;
}




void Battlefield::updatePlayer(float tickSize)
{
    if (m_player)
    {
        m_player->update(tickSize);

        if (player()->doDelete())
        m_player = nullptr;
    }
}


void Battlefield::updateRedBullets(float tickSize)
{
    t_red_bullets.updateAll(tickSize);

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

void Battlefield::updateBlueBullets(float tickSize)
{
    t_blue_bullets.updateAll(tickSize);

    if (m_player)
    {
        for (auto bullet_p : t_blue_bullets)
        {
            bullet_p->testHarming(*m_player);
        }
    }
}

void Battlefield::updateEnemies(float tickSize)
{
    t_enemies.updateAll(tickSize, false);

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


void Battlefield::drawEnemiesIn(AbstractDrawer& fenetre)
{
    t_enemies.drawAllIn(fenetre);
}

void Battlefield::drawBlueShotsIn(AbstractDrawer& fenetre)
{
    t_blue_bullets.drawAllIn(fenetre);
}

void Battlefield::drawRedShotsIn(AbstractDrawer& fenetre)
{
    t_red_bullets.drawAllIn(fenetre);
}

void Battlefield::drawPlayerIn(AbstractDrawer& fenetre)
{
    if (m_player)
    m_player->drawIn(fenetre);
}




void Battlefield::updateAll(float tickSize)
{
    updatePlayer(tickSize);
    updateEnemies(tickSize);
    updateRedBullets(tickSize);
    updateBlueBullets(tickSize);
}


void Battlefield::drawAllIn(AbstractDrawer& fenetre)
{
    drawBlueShotsIn(fenetre);
    drawRedShotsIn(fenetre);
    drawEnemiesIn(fenetre);
    drawPlayerIn(fenetre);
}


void Battlefield::givePlayer(Weapon* w)
{
    w->setBulletArray(&t_red_bullets);
    m_player->addWeapon(w);
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













