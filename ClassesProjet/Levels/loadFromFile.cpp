

#include "loadFromFile.h"

/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, adress TEXT)
**/
void loadTextureList(TextureList& list, sql3::Database& db, const std::string& tableName)
{
    std::string query = "SELECT * FROM " + tableName;

    std::map<std::string, std::string> textureAdresses;

    std::function<void(const sql3::Statement&, unsigned int)> f = [&textureAdresses](const sql3::Statement& stmt, unsigned int i)
    {
        std::string name = stmt.columnStandardText(1);
        std::string filename = stmt.columnStandardText(2);

        textureAdresses[name] = filename;
    };

    sql3::execute(db, f, query.c_str(), query.size());
    list.loadTextures(textureAdresses);
}


/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, spriteName TEXT, x1 INTEGER, x2 INTEGER,
                        width INTEGER, height INTEGER, speed REAL, score INTEGER, life INTEGER, canShoot INTEGER)
**/
void loadEnemyStats(BasicSpaceLevel& level, sql3::Database& db, const std::string& tableName)
{
    std::string query = "SELECT * FROM " + tableName;
    std::map<std::string, EnemiesStats> statsList;

    std::function<void(const sql3::Statement&, unsigned int)> f = [&statsList](const sql3::Statement& stmt, unsigned int i)
    {
        std::string name = stmt.columnStandardText(1);
        std::string spriteName = stmt.columnStandardText(2);
        int x1 = stmt.columnInt(3); // hitbox
        int y1 = stmt.columnInt(4);
        int width = stmt.columnInt(5);
        int height = stmt.columnInt(6);

        float speed = stmt.columnDouble(7);
        int scoreValue = stmt.columnInt(8);
        int hp = stmt.columnInt(9);
        bool shoots = (stmt.columnInt(10) >= 0);

        statsList[name] = EnemiesStats(spriteName, sf::IntRect(x1, y1, width, height), speed, scoreValue, hp, shoots);

        return;
    };

    sql3::execute(db, f, query.c_str(), query.size());
    level.setStats(statsList);
}



/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, enemyName TEXT, delay REAL)
**/
void loadEnemyWave(WaveSpaceLevel& level, sql3::Database& db, const std::string& tableName)
{
    std::string query = "SELECT * FROM " + tableName;

    std::function<void(const sql3::Statement&, unsigned int)> f = [&level](const sql3::Statement& stmt, unsigned int i)
    {
        std::string statsName = stmt.columnStandardText(1);
        float delayUntilNext = stmt.columnDouble(2);

        level.addEnemy(statsName, delayUntilNext);
    };

    sql3::execute(db, f, query.c_str(), query.size());
}




