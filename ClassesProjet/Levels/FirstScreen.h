

#ifndef FIRST_SCREEN_HEADER
#define FIRST_SCREEN_HEADER

#include "../Moteur2D.h"
#include "SpaceStats.h"

#define TEXT_SIZE 50
#define FIRST_SCREEN_TEXT_L1 "Invasion"
#define FIRST_SCREEN_TEXT_L2 "de L'ESPACE"

class FirstScreen : public PressAnyKeyMenu<float>
{
    public :

    explicit FirstScreen(const sf::Font* f = nullptr, sf::Color c = sf::Color::White, AbstractInputs* in = nullptr);
    void setText(const sf::Font* f, sf::Color c = sf::Color::White);
    void drawIn(AbstractDrawer& window);

    private :

    Menu::ItemGrid m_grid;
    Menu::Text* m_text_1;
    Menu::Text* m_text_2;
};






#endif // FIRST_SCREEN_HEADER
