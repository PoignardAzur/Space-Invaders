
#include "FirstScreen.h"
#include "../MainDimensions.h"

FirstScreen::FirstScreen(const sf::Font& f, sf::Color c, AbstractInputs* in)
{
    setText(f, c);
    setUserInputs(in);
}

void FirstScreen::setText(const sf::Font& f, sf::Color c)
{
    m_font = f;

    m_text_1.setFont(m_font, 50);
    m_text_1.setColor(c);
    m_text_1.setDisplayedText("Invasion");
    m_text_1.setPosition(sf::Vector2f(LARGEUR_FENETRE / 2, (HAUTEUR_FENETRE - HAUTEUR_HUD) / 2 - 60), Center);

    m_text_2.setFont(m_font, 50);
    m_text_2.setColor(c);
    m_text_2.setDisplayedText("de l'ESPACE");
    m_text_2.setPosition(sf::Vector2f(LARGEUR_FENETRE / 2, (HAUTEUR_FENETRE - HAUTEUR_HUD) / 2), Center);
}

void FirstScreen::drawIn(AbstractDrawer& window)
{
    window.draw(m_text_1);
    window.draw(m_text_2);
}

