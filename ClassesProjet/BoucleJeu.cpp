
#include "BoucleJeu.h"

#define MAIN_LOADING_FILE "mainFile.json"


BoucleJeu::BoucleJeu(AbstractInputs* in, sf::RenderWindow* cible)
{
    // LOAD CAMPAIGN
    m_level->setUserInputs(windowInputs());
    m_loader.setLevel(m_level, m_textureList, m_statsList);
}

void BoucleJeu::set2(AbstractInputs* in, sf::RenderWindow* cible)
{
    set(in, cible);
    m_loader.loadFromFile(MAIN_LOADING_FILE);

    m_loader.loadFont(m_font);
    m_loader.loadMenuTextures(m_textureList);
    m_loader.loadFirstScreen(m_firstScreen);
    // drawMenu;

    m_loader.loadTextures(m_textureList);
    //m_loader.loadMenu
    m_loader.loadCampaign(m_campaign);

    m_hud.setAllFonts(&m_font, sf::Color::White);
    m_hud.setLifeSprite(sf::Sprite(m_textureList[LIFE_TEXTURE_NAME]));
}





AbstractGameInterface<float>* BoucleJeu::interface()
{
    return &m_interface;
}



void BoucleJeu::drawEverything(float dt)
{
    m_interface.drawIn(*renderingWindow());
}


void BoucleJeu::update(float dt)
{
    interface()->update(dt);
    windowInputs()->update();

    drawEverything(dt);
}





