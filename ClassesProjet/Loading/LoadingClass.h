


#ifndef LOADING_CLASS_HEADER
#define LOADING_CLASS_HEADER


#include "../Levels/RandomSpaceLevel.h"
#include "../Levels/SpaceHUD.h"

#include "../../rapidjson/document.h"
#include <functional>

#define TEXTURE_TABLE_NAME "EnemyTextures"
#define ENEMIES_TABLE_NAME "EnemyStats"
#define WEAPONS_TABLE_NAME "Weapons"
#define WAVES_TABLE_NAME "EnemyWaves"

#define MAIN_DATABASE "Ressources\\DatabaseFile.txt"


namespace json = rapidjson;

class Loader
{
    public :

    Loader();

    void setTextureList(TextureList& list);
    void setBaseTextureList(TextureList& list);
    void setEnemyStats(ResourceList<EnemiesStats>& statsList);
    void setLevel(RandomSpaceLevel* level, TextureList& t, ResourceList<EnemiesStats>& s);

    void loadFromFile(const char* fileName);
    void loadFont(sf::Font& font);
    void loadMenuTextures(TextureList& textureList);
    void loadFirstScreen(FirstScreen& screen);
    void loadTextures(TextureList& textureList);
    //void loadMenu(Menu)
    void loadCampaign(Campaign& mainCampaign);

    private :

    json::Document m_document;

};



#endif // LOADING_CLASS_HEADER




