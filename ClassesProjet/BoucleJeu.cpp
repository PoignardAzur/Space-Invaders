

#include "BoucleJeu.h"


BoucleJeu::BoucleJeu(AbstractInputs* in, sf::RenderWindow* cible) : m_level(new RandomSpaceLevel)
{
    set(in, cible);
    m_level->setUserInputs(windowInputs());

    m_font.loadFromFile(DEFAULT_FONT_NAME);
    FirstScreen* screen = new FirstScreen(&m_font, sf::Color::White, windowInputs());

    SpaceHUD* hud = new SpaceHUD(m_level);
    m_interface.addInterface(hud);
    m_interface.addInterface(screen);

    drawEverything(0);

    m_loader.setBaseTextureList(m_textureList);
    m_loader.setLevel(m_level, m_textureList, m_statsList);
    m_loader.setHUD(m_textureList, hud, &m_font);
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





