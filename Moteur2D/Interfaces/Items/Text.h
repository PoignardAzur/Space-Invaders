


#ifndef MENU_TEXT_HEADER
#define MENU_TEXT_HEADER


#include "AbstractItem.h"
#include <string>

#define DEFAULT_FONT_SIZE 30

namespace Menu
{

    class Text : public AbstractItem
    {
        public :

        explicit Text(const std::string& str = "", const sf::Font* f = nullptr, unsigned int charSize = DEFAULT_FONT_SIZE, const sf::Color& c = sf::Color::Black);
        explicit Text(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE, const sf::Color& c = sf::Color::Black);

        void setString(const std::string& str);
        void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
        void setColor(const sf::Color& c);
        sf::Vector2f size() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        sf::Font* m_font;
        sf::Color m_color;
        sf::Text m_text;
    };


}


#endif // MENU_TEXT_HEADER




