


#ifndef BASIC_SPACE_LEVEL_HEADER
#define BASIC_SPACE_LEVEL_HEADER

#define IDLE_PLAYER_TEXTURE_NAME "idle"
#define SHOOTING_PLAYER_TEXTURE_NAME "shooting"
#define PLAYER_BULLET_SPRITE_NAME "redBullet"

#include "../../Moteur2D/Interfaces/BasicArcadeLevel.h"
#include "../TextureList.h"
#include "Battlefield.h"

#include <queue>
#include "Waves/AbsWave.h"


class BasicSpaceLevel : public Battlefield, public BasicArcadeLevel<float>
{
    public :

    BasicSpaceLevel(sf::FloatRect visibleZone = sf::FloatRect(0,0,0,0));
    virtual ~BasicSpaceLevel();

    virtual void setVisibleZone(sf::FloatRect visibleZone);
    virtual void setSprites(sf::Sprite idlePlayer, sf::Sprite shootingPlayer, sf::Sprite bulletSprite);

    virtual void addWave(AbsWave* wave);
    virtual bool levelComplete() const;

    virtual void update(const float& dt);
    virtual void drawIn(AbstractDrawer& fenetre);

    virtual bool isPlayerAlive() const;
    virtual void respawnPlayer();
    virtual void playerKilled(bool isGameOver);     // whenever the player dies, this function is called

    protected :

    virtual bool enemyEscapes(std::shared_ptr<Enemy>& e);
    virtual void enemyDies(std::shared_ptr<Enemy>& e);
    void bomb(bool scorePoints = true);

    virtual void generateEnemyWaves(float dt);


    private :

    TextureList* m_textureList;                                 // use-a
    std::map<std::string, EnemiesStats> m_statsList;

    float m_leftLimit;
    float m_rightLimit;

    sf::Sprite m_idlePlayer;
    sf::Sprite m_shootingPlayer;
    sf::Sprite m_bulletSprite;

    std::queue<std::shared_ptr<AbsWave>> m_waves;
};










#endif

