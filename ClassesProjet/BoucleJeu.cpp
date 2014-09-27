

#include "BoucleJeu.h"


BoucleJeu::BoucleJeu(AbstractInputs* in, sf::RenderWindow* cible) : m_level(new RandomSpaceLevel)
{
    m_window = cible;
    set(in, cible);
    m_level->setUserInputs(windowInputs());

    m_font.loadFromFile(DEFAULT_FONT_NAME);
    FirstScreen* screen = new FirstScreen(&m_font, sf::Color::White, windowInputs());

    screen->drawIn(*renderingWindow());
    cible->display();

    SpaceHUD* hud = new SpaceHUD(m_level);
    m_interface.addInterface(hud);

    m_interface.addInterface(screen);

    drawEverything(0);

    m_loader.setBaseTextureList(m_textureList);
    m_loader.setLevel(m_level, m_textureList);
    m_loader.setHUD(m_textureList, hud, &m_font);
}







AbstractGameInterface<float>* BoucleJeu::interface()
{
    return &m_interface;
}



void BoucleJeu::drawEverything(float tickSize)
{
    m_interface.drawIn(*renderingWindow());
}


void BoucleJeu::update(float tickSize)
{
    interface()->update(tickSize);
    windowInputs()->update();

    drawEverything(tickSize);
}





