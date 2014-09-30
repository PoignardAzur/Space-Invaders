


#ifndef LOADING_CLASS_HEADER
#define LOADING_CLASS_HEADER


#include "../Levels/RandomSpaceLevel.h"
#include "../Levels/SpaceHUD.h"

#include "../../SQLite/statement.hpp"
#include <functional>
#include <fstream>

#define TEXTURE_TABLE_NAME "EnemyTextures"
#define ENEMIES_TABLE_NAME "EnemyStats"
#define WEAPONS_TABLE_NAME "Weapons"
#define WAVES_TABLE_NAME "EnemyWaves"

#define MAIN_DATABASE "Ressources\\DatabaseFile.txt"
#define COMMAND_FILE  "Ressources\\CommandFile.txt"


namespace sql3 { class Database; }

class Loader
{
    public :

    Loader();

    void setTextureList(TextureList& list);
    void setBaseTextureList(TextureList& list);
    void setEnemyStats(ResourceList<EnemiesStats>& statsList);
    void setLevel(RandomSpaceLevel* level, TextureList& t, ResourceList<EnemiesStats>& s);
    void setHUD(TextureList& t, SpaceHUD* hud, sf::Font* f);


    private :

    sql3::Database m_database;

};



#endif // LOADING_CLASS_HEADER




