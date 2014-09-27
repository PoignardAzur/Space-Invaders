
#include "FirstScreen.h"
#include "../MainDimensions.h"

FirstScreen::FirstScreen(const sf::Font* f, sf::Color c, AbstractInputs* in)
{
    m_text_1 = new Menu::Text(FIRST_SCREEN_TEXT_L1);
    m_text_2 = new Menu::Text(FIRST_SCREEN_TEXT_L2);

    std::vector<std::shared_ptr<Menu::AbstractItem>> items =
    {std::shared_ptr<Menu::AbstractItem>(m_text_1), std::shared_ptr<Menu::AbstractItem>(m_text_2)};

    m_grid.setAsColumn(items, 0);
    m_grid.setInternPosition(Menu::MiddleBottomSide, sf::Vector2f(0, 10));

    setText(f, c);
    setUserInputs(in);
}

void FirstScreen::setText(const sf::Font* f, sf::Color c)
{
    m_text_1->setFont(f, TEXT_SIZE);
    m_text_1->setColor(c);

    m_text_2->setFont(f, TEXT_SIZE);
    m_text_2->setColor(c);
}

void FirstScreen::drawIn(AbstractDrawer& window)
{
    m_grid.drawInBox(window, sf::FloatRect(0, 0, LARGEUR_FENETRE, 0.6 * HAUTEUR_FENETRE), Menu::Center);
}

