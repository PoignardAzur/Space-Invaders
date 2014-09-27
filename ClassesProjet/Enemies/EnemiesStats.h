


#ifndef ENEMIES_STATS
#define ENEMIES_STATS

#define DEFAULT_ENEMY_SHOT_NAME "blueShot"


struct EnemiesStats
{
    std::string spriteName;
    sf::IntRect hitbox;
    float speed;
    int scoreValue;
    int hp;

    bool shoots;

    EnemiesStats() {}
    EnemiesStats(const std::string& sprName, sf::IntRect nHitbox, float nSpeed, int nScoreValue, int nHP, bool nShoots = false) :
    spriteName(sprName), hitbox(nHitbox), speed(nSpeed), scoreValue(nScoreValue), hp(nHP), shoots(nShoots) {}
};


/*EnemiesStats::EnemiesStats(sf::Sprite nSpr, sf::IntRect nHitbox) : spr(nSpr), hitbox(nHitbox)
{

}
*/

#endif

