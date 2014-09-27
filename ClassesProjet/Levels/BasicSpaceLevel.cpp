


#include "BasicSpaceLevel.h"
#include <cassert>

#define DEFAULT_FIRE_RATE 0.5f


BasicSpaceLevel::BasicSpaceLevel(unsigned int seed, PlayerShip* player, sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
Battlefield(player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight), BasicArcadeLevel<float>(seed)
{
    setRespawnTime(TIME_BEFORE_RESPAWN);
}

BasicSpaceLevel::BasicSpaceLevel(std::seed_seq& seed, PlayerShip* player, sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight) :
Battlefield(player, visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight), BasicArcadeLevel<float>(seed)
{
    setRespawnTime(TIME_BEFORE_RESPAWN);
}

BasicSpaceLevel::~BasicSpaceLevel()
{

}



void BasicSpaceLevel::useTextureList(TextureList* t)
{
    m_textureList = t;
}

void BasicSpaceLevel::setStats(const std::map<std::string, EnemiesStats>& statsList)
{
    m_statsList = statsList;
}


void BasicSpaceLevel::setLimits(float leftLimit, float rightLimit)
{
    m_leftLimit = leftLimit;
    m_rightLimit = rightLimit;
}


void BasicSpaceLevel::setZones(sf::FloatRect visibleZone, float leftSpawnLimit, float rightSpawnLimit, float spawnHeight)
{
    Battlefield::setZones(visibleZone, leftSpawnLimit, rightSpawnLimit, spawnHeight);
    setLimits(leftSpawnLimit, rightSpawnLimit);
}



void BasicSpaceLevel::update(const float& tickSize)
{
    Battlefield::updateAll(tickSize);
    BasicArcadeLevel<float>::updateLivesAndTimer(tickSize);

    if (isPlayerAlive())
    generateEnemyWaves(tickSize);
}


void BasicSpaceLevel::drawIn(AbstractDrawer& fenetre)
{
    Battlefield::drawAllIn(fenetre);
}


bool BasicSpaceLevel::isPlayerAlive() const
{
    return player();
}

void BasicSpaceLevel::respawnPlayer()
{
    PlayerShip* p = new PlayerShip();
    sf::Sprite idlePlayer(*texture(IDLE_PLAYER_TEXTURE_NAME));
    sf::Sprite shootingPlayer(*texture(SHOOTING_PLAYER_TEXTURE_NAME));
    sf::Sprite bulletSprite(*texture(PLAYER_BULLET_SPRITE_NAME));

    p->setLimits(m_leftLimit, m_rightLimit);
    p->setSprites(idlePlayer, shootingPlayer);
    p->setInputs(BasicArcadeLevel<float>::getInputs());

    p->move(POSITION_PLAYER_SHIP, false);
    p->setHitbox(HITBOX_PLAYER_SHIP);

    Battlefield::setPlayer(p);

    Weapon* w = new Weapon(DEFAULT_FIRE_RATE);
    w->setBulletSprite(bulletSprite);
    givePlayer(w);
}


void BasicSpaceLevel::playerKilled(bool isGameOver)
{
    if (!isGameOver)
    bomb(false);
}



TextureList* BasicSpaceLevel::textureList()
{
    return m_textureList;
}

const sf::Texture* BasicSpaceLevel::texture(const std::string& name) const
{
    return m_textureList->texture(name);
}


void BasicSpaceLevel::generateEnemy(const std::string& name)
{
    const EnemiesStats& stats = m_statsList[name];
    generateFromStats(stats, randomGenerator(), texture(stats.spriteName), texture(DEFAULT_ENEMY_SHOT_NAME));
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
















