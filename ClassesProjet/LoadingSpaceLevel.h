



#ifndef LOANDING_SPACE_LEVEL_HEADER
#define LOANDING_SPACE_LEVEL_HEADER

#include "SpaceLevel.h"

#define TEXTURE_TABLE_NAME "EnemyTextures"
#define ENEMIES_TABLE_NAME "EnemyStats"
#define WEAPONS_TABLE_NAME "Weapons"
#define WAVES_TABLE_NAME "EnemyWaves"



class LoadingSpaceLevel : public SpaceLevel
{
    public :

    LoadingSpaceLevel();

    void setTexturesFromFiles(sql3::Database& db);
    void setEnemiesFromFile(sql3::Database& db);
    void setWeaponsFromFile(sql3::Database& db);
    void setWavesFromFile(sql3::Database& db);

    void testSize(u_short i);
};




#endif

