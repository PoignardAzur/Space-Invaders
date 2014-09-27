

#ifndef LOAD_FROM_FILE_HEADER
#define LOAD_FROM_FILE_HEADER

#include "WaveSpaceLevel.h"
#include "../../SQLite/statement.hpp"
#include <functional>


#define TEXTURE_TABLE_NAME "EnemyTextures"
#define ENEMIES_TABLE_NAME "EnemyStats"
#define WEAPONS_TABLE_NAME "Weapons"
#define WAVES_TABLE_NAME "EnemyWaves"




void loadTextureList(TextureList& list, sql3::Database& db, const std::string& tableName = TEXTURE_TABLE_NAME);
void loadEnemyStats(BasicSpaceLevel& level, sql3::Database& db, const std::string& tableName = ENEMIES_TABLE_NAME);
void loadEnemyWave(WaveSpaceLevel& level, sql3::Database& db, const std::string& tableName = WAVES_TABLE_NAME);




#endif // LOAD_FROM_FILE_HEADER


