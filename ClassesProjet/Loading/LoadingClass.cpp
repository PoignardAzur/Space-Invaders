

#include "LoadingClass.h"


Loader::Loader()
{
    std::ifstream file(COMMAND_FILE);

    if (file.is_open())
    createDatabaseFromFile(m_database, file, MAIN_DATABASE, &std::cerr, true);

    else
    m_database.open(MAIN_DATABASE);
}


/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, adress TEXT)
**/
void Loader::setTextureList(TextureList& list)
{
    std::string query = "SELECT * FROM ";
    query += TEXTURE_TABLE_NAME;

    std::map<std::string, std::string> textureAdresses;

    std::function<void(const sql3::Statement&, unsigned int)> f = [&textureAdresses](const sql3::Statement& stmt, unsigned int i)
    {
        std::string name = stmt.columnStandardText(1);
        std::string filename = stmt.columnStandardText(2);

        textureAdresses[name] = filename;
    };

    sql3::execute(m_database, f, query.c_str(), query.size());
    list.loadTextures(textureAdresses);
}



void Loader::setBaseTextureList(TextureList& t)
{
    std::map<std::string, std::string> textures;

    textures[LIFE_TEXTURE_NAME] = "Ressources\\Images\\Vie.bmp";
    textures[IDLE_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur.bmp";
    textures[SHOOTING_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur_Charge.bmp";
    textures[PLAYER_BULLET_SPRITE_NAME] = "Ressources\\Images\\Tir.bmp";
    textures[DEFAULT_ENEMY_SHOT_NAME] = "Ressources\\Images\\Tir_Ennemi.bmp";

    t.loadBaseTextures(textures);
}


/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, spriteName TEXT, x1 INTEGER, x2 INTEGER,
                        width INTEGER, height INTEGER, speed REAL, score INTEGER, life INTEGER, canShoot INTEGER)
**/
void Loader::setEnemyStats(BasicSpaceLevel& level)
{
    std::string query = "SELECT * FROM ";
    query += ENEMIES_TABLE_NAME;
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

        statsList[name] = EnemiesStats(spriteName, sf::FloatRect(x1, y1, width, height), speed, scoreValue, hp, shoots);

        return;
    };

    sql3::execute(m_database, f, query.c_str(), query.size());
    level.setStats(statsList);
}


/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, enemyName TEXT, delay REAL)
**/
void Loader::setEnemyWave(WaveSpaceLevel& level)
{
    std::string query = "SELECT * FROM ";
    query += WAVES_TABLE_NAME;

    std::function<void(const sql3::Statement&, unsigned int)> f = [&level](const sql3::Statement& stmt, unsigned int i)
    {
        std::string statsName = stmt.columnStandardText(1);
        float delayUntilNext = stmt.columnDouble(2);

        level.addEnemy(statsName, delayUntilNext);
    };

    sql3::execute(m_database, f, query.c_str(), query.size());
}


void Loader::setLevel(RandomSpaceLevel* level, TextureList& t)
{
    level->setZones(sf::FloatRect(0,0, LARGEUR_FENETRE, HAUTEUR_FENETRE), 0, LARGEUR_FENETRE, HAUTEUR_SPAWN);
    level->useTextureList(&t);

    level->respawnPlayer();

    setTextureList(t);
    setEnemyStats(*level);
///    loadEnemyWave(*level, m_database);                               - TO CHANGE

    std::vector<std::string> names = {"mook", "boosted", "shooter", "invis"};
    level->setNames(names);
    level->setLives(NUMBER_OF_LIVES);
}


void Loader::setHUD(TextureList& t, SpaceHUD* hud, sf::Font* f)
{
    hud->setAllFonts(f, sf::Color::White);
    hud->setLifeSprite(sf::Sprite( *t.texture(LIFE_TEXTURE_NAME) ));
}





