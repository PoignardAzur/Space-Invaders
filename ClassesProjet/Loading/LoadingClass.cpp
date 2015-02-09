

#include "LoadingClass.h"
#include <fstream>
#include <string>

#define DEFAULT_FONT_NAME "Ressources/arial.ttf"


Loader::Loader()
{

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





/**
Creating table :
CREATE TABLE tableName (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, spriteName TEXT, x1 INTEGER, x2 INTEGER,
                        width INTEGER, height INTEGER, speed REAL, score INTEGER, life INTEGER, canShoot INTEGER)
**/
void Loader::setEnemyStats(ResourceList<EnemiesStats>& statsList)
{
    std::string query = "SELECT * FROM ";
    query += ENEMIES_TABLE_NAME;

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
}



void Loader::setLevel(RandomSpaceLevel* level, TextureList& t, ResourceList<EnemiesStats>& s)
{

    setTextureList(t);
    setEnemyStats(s);

}



void Loader::loadFromFile(const char* fileName)
{
    std::string fileContent;
    std::string line;
    std::ifstream file(fileName);

    if (!file.open())
    {
        throw (std::string(filename) + " could not be open.").c_str();
    }

    while (std::getline(file, line)
    {
        fileContent += line;
    }

    m_document.Parse(fileContent.c_str());
}

void Loader::loadFont(sf::Font& font)
{
    m_font.loadFromFile(DEFAULT_FONT_NAME);
}

void Loader::loadMenuTextures(TextureList& textureList)
{
    std::map<std::string, std::string> textures;
    textures[LIFE_TEXTURE_NAME] = "Ressources\\Images\\Vie.bmp";
    textureList.load(textures);
}

void Loader::loadFirstScreen(FirstScreen& screen)
{
    screen.setText(&m_font, sf::Color::White);
    screen.setInputs(windowInputs());
}

void Loader::loadTextures(TextureList& textureList)
{
    std::map<std::string, std::string> textures;

    textures[IDLE_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur.bmp";
    textures[SHOOTING_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur_Charge.bmp";
    textures[PLAYER_BULLET_SPRITE_NAME] = "Ressources\\Images\\Tir.bmp";
    textures[DEFAULT_ENEMY_SHOT_NAME] = "Ressources\\Images\\Tir_Ennemi.bmp";

    textureList.loadTextures(textures);
}

//void Loader::loadMenu(Menu)
{

}

void Loader::loadCampaign(Campaign& mainCampaign)
{

}


