


#ifndef SPAWNING_RATE_HEADER
#define SPAWNING_RATE_HEADER


struct SpawningRate
{
    int min;
    int max;
    int enemyNumber;

    SpawningRate(int nMin, int nMax, int nEnemyNumber) : min(nMin), max(nMax), enemyNumber(nEnemyNumber) {}
    SpawningRate() {}

};





#endif

