

#include "Campaign.h"
#include <string>


Campaign::Campaign()
{
    m_selectedLevel = 0;
}

void Campaign::setLevel()
{
    if (m_level)
    delete m_level;

    const TextureList& t = *m_textures;
    sf::Sprite idlePlayer(t[IDLE_PLAYER_TEXTURE_NAME]);
    sf::Sprite shootingPlayer(t[SHOOTING_PLAYER_TEXTURE_NAME]);
    sf::Sprite bulletSprite(t[PLAYER_BULLET_SPRITE_NAME]);

    m_level = new BasicSpaceLevel(sf::FloatRect(0,0, LARGEUR_FENETRE, HAUTEUR_FENETRE));
    m_level->setLives(NUMBER_OF_LIVES);
    m_level->setSprites(idlePlayer, shootingPlayer, bulletSprite);

    try
    json::Document levelData = loadLevelData(m_levelList, m_selectedLevel);



    m_level->setResources(m_textures, m_stats);

    m_selectedLevel++;
    level->respawnPlayer();
}

void Campaign::drawIn(AbstractDrawer& window)
{

}

void Campaign::update(const float& dt)
{

}


json::Document loadLevelData(const json::Value* levelList, size_t selectedLevel)
{
    if (!levelList->IsArray())
    throw "Error : levelList is not an array";

    if (selectedLevel >= levelList->Size())
    throw "Error : trying to selected a non-existent level";

    if (!levelList[selectedLevel].HasMember("file"))
    throw "Error : level " + std::to_string(selectedLevel) + " has no file";

    std::ifstream currentLevelFile(levelList[selectedLevel]["file"].getString());

    if (!currentLevelFile)
    throw std::string("Error : could not load ") + levelList[selectedLevel]["file"].getString();

    std::string currentLevelString;
    for (std::string line; currentLevelFile; std::getline(currentLevelFile, line));

    return currentLevel(currentLevelString.c_str());
}





