


#ifndef ENEMIES_STATS
#define ENEMIES_STATS


struct EnemiesStats
{
    int spriteNumber;
    sf::IntRect hitbox;
    float speed;
    int scoreValue;
    int hp;

    bool shoots;

    EnemiesStats(int sprNumber, sf::IntRect nHitbox, float nSpeed, int nScoreValue, int nHP, bool nShoots = false) :
    spriteNumber(sprNumber), hitbox(nHitbox), speed(nSpeed), scoreValue(nScoreValue), hp(nHP), shoots(nShoots) {}
};


/*EnemiesStats::EnemiesStats(sf::Sprite nSpr, sf::IntRect nHitbox) : spr(nSpr), hitbox(nHitbox)
{

}
*/

#endif

