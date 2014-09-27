

#ifndef FIRST_SCREEN_HEADER
#define FIRST_SCREEN_HEADER

#include "../Moteur2D.h"
#include "SpaceStats.h"
#include "../../Moteur2D/Graphic/Text.h"

class FirstScreen : public PressAnyKeyMenu<float>
{
    public :

    explicit FirstScreen(const sf::Font& f = sf::Font(), sf::Color c = sf::Color::White, AbstractInputs* in = nullptr);
    void setText(const sf::Font& f, sf::Color c = sf::Color::White);
    void drawIn(AbstractDrawer& window);

    private :

    DrawableText m_text_1;
    DrawableText m_text_2;
    sf::Font m_font;
};






#endif // FIRST_SCREEN_HEADER
