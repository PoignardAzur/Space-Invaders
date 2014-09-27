


#include "Text.h"


Menu::Text::Text(const std::string& str, const sf::Font* f, unsigned int charSize, const sf::Color& c)
{
    setString(str);
    setFont(f, charSize);
    setColor(c);
}

Menu::Text::Text(const sf::Font* f, unsigned int charSize, const sf::Color& c)
{
    setFont(f, charSize);
    setColor(c);
}



void Menu::Text::setString(const std::string& str)
{
    m_text.setString(str);
    updateParentSize();
}

void Menu::Text::setFont(const sf::Font* f, unsigned int charSize)
{
    m_text.setFont(*f);
    m_text.setCharacterSize(charSize);

    updateParentSize();
}

void Menu::Text::setColor(const sf::Color& c)
{
    m_text.setColor(c);
}


void Menu::Text::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    const_cast<Text*>(this)->m_text.setPosition(position.x, position.y - m_text.getLocalBounds().top);
    target.draw(m_text);
}

sf::Vector2f Menu::Text::size() const
{
    return sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height);
}






