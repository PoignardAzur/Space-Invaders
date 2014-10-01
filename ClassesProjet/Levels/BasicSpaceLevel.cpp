


#include "BasicSpaceLevel.h"
#include <cassert>

#define DEFAULT_FIRE_RATE 0.5f


BasicSpaceLevel::BasicSpaceLevel(sf::FloatRect visibleZone) : Battlefield(visibleZone)
{
    setRespawnTime(TIME_BEFORE_RESPAWN);
}

BasicSpaceLevel::~BasicSpaceLevel()
{

}


void BasicSpaceLevel::setVisibleZone(sf::FloatRect visibleZone)
{
    Battlefield::setVisibleZone(visibleZone);
    m_leftLimit = visibleZone.left;
    m_rightLimit = visibleZone.left + visibleZone.width;
}

void BasicSpaceLevel::setSprites(sf::Sprite idlePlayer, sf::Sprite shootingPlayer, sf::Sprite bulletSprite)
{
    m_idlePlayer = idlePlayer;
    m_shootingPlayer = shootingPlayer;
    m_bulletSprite = bulletSprite;
}

void BasicSpaceLevel::addWave(AbsWave* wave)
{
    wave->setTarget(enemies());
    m_waves.push(std::shared_ptr<AbsWave>(wave));
}


void BasicSpaceLevel::update(const float& dt)
{
    Battlefield::updateAll(dt);
    BasicArcadeLevel<float>::updateLivesAndTimer(dt);

    if (isPlayerAlive())
    generateEnemyWaves(dt);
}


void BasicSpaceLevel::drawIn(AbstractDrawer& fenetre)
{
    Battlefield::drawAllIn(fenetre);
}


void BasicSpaceLevel::generateEnemyWaves(float dt)
{
    if (!m_waves.size())
    return;

    else if (m_waves.front()->update(dt))
    m_waves.pop();
}



bool BasicSpaceLevel::isPlayerAlive() const
{
    return player();
}


void BasicSpaceLevel::respawnPlayer()
{
    PlayerShip* p = new PlayerShip();

    p->setLimits(m_leftLimit, m_rightLimit);
    p->setSprites(m_idlePlayer, m_shootingPlayer);
    p->setInputs(BasicArcadeLevel<float>::getInputs());

    p->move(POSITION_PLAYER_SHIP, false);
    p->setHitbox(HITBOX_PLAYER_SHIP);

    Weapon* w = new Weapon(DEFAULT_FIRE_RATE);
    w->setBulletSprite(m_bulletSprite);
    w->setBulletArray(redBullets());
    p->addWeapon(w);

    Battlefield::setPlayer(p);
}


void BasicSpaceLevel::playerKilled(bool isGameOver)
{
    if (!isGameOver)
    bomb(false);
}


bool BasicSpaceLevel::enemyEscapes(std::shared_ptr<Enemy>& e)
{
    if (Battlefield::player())
    Battlefield::player()->kill();

    return false;
}

void BasicSpaceLevel::enemyDies(std::shared_ptr<Enemy>& e)
{
    BasicArcadeLevel::setPoints(e->score(), true);
}


void BasicSpaceLevel::bomb(bool scorePoints)
{
    Battlefield::killAllEnemies(true, scorePoints);
}
















