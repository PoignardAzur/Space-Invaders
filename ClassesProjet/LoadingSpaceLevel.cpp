


#include "LoadingSpaceLevel.h"




LoadingSpaceLevel::LoadingSpaceLevel() : SpaceLevel ()
{

}


void LoadingSpaceLevel::setTexturesFromFiles(sql3::Database& db)
{
    sql3::Statement stmt;
    stmt.prepareIn(db, "SELECT * FROM " TEXTURE_TABLE_NAME);
    u_short i = 0;

    while (!stmt.step())
    {
        t_enemyTextures.resize(i+1);

        if (!t_enemyTextures[i].loadFromFile( stmt.columnStandardText(1) ))
        {
            std::stringstream ss;
            ss << i;
            throw std::string("The texture n°") + ss.str() + std::string(" could not be charged");
        }

        Sprite::createMaskFromColor(t_enemyTextures[i], sf::Color::White);
        i++;
    }

    testSize(i);
}

void LoadingSpaceLevel::setWeaponsFromFile(sql3::Database& db)
{
    sql3::Statement stmt;
    stmt.prepareIn(db, "SELECT * FROM " WEAPONS_TABLE_NAME);
    u_short i = 0;

    while (!stmt.step())
    {
//        t_weapons.push_back();
        i++;
    }

    testSize(i);
}

void LoadingSpaceLevel::setEnemiesFromFile(sql3::Database& db)
{
    sql3::Statement stmt;
    stmt.prepareIn(db, "SELECT * FROM " ENEMIES_TABLE_NAME);
    u_short i = 0;

    while (!stmt.step())
    {
        t_enemyTypes.push_back(  EnemiesStats( stmt.columnInt(1), sf::IntRect(stmt.columnInt(2), stmt.columnInt(3), stmt.columnInt(4), stmt.columnInt(5)), stmt.columnInt(6), stmt.columnInt(7), stmt.columnInt(8), (stmt.columnInt(9) >= 0) )  );
        i++;
    }

    testSize(i);
}



void LoadingSpaceLevel::setWavesFromFile(sql3::Database& db)
{
    sql3::Statement stmt;
    stmt.prepareIn(db, "SELECT * FROM " WAVES_TABLE_NAME);
    u_short i = 0;

    while (!stmt.step())
    {
        t_spawners.resize(i+1);
        t_spawners[i].first.setTime(stmt.columnInt(1));
        t_spawners[i].second = SpawningRate(stmt.columnInt(2), stmt.columnInt(3), stmt.columnInt(4));
        i++;
    }

    testSize(i);
}


void LoadingSpaceLevel::testSize(u_short i)
{
    if (!i)
    {
        throw "One table is void";
    }
}

