

#include "Text.h"


DrawableText::DrawableText(const sf::Text& t, bool rightAligned)
{
    set(t, rightAligned);
}

DrawableText::DrawableText(const char* text, sf::Vector2f pos, const sf::Font& f, const sf::Color& c, bool rightAligned)
{
    setPosition(pos);
    setFont(f);
    setColor(c);

    setDisplayedText(text);
    setRightAligned(rightAligned);
}

void DrawableText::set(const sf::Text& t, bool rightAligned)
{
    m_image = t;
    setRightAligned(rightAligned);
}

void DrawableText::set(const char* text, sf::Vector2f pos, const sf::Font& f, const sf::Color& c, bool rightAligned)
{
    setPosition(pos);
    setFont(f);
    setColor(c);

    setDisplayedText(text);
    setRightAligned(rightAligned);
}


void DrawableText::setRightAligned(bool right)
{
    m_rightAligned = right;
    realign();
}

void DrawableText::setFont(const sf::Font& f, int size)
{
    m_image.setFont(f);
    m_image.setCharacterSize(size);
}

void DrawableText::setColor(const sf::Color& c)
{
    m_image.setColor(c);
}

void DrawableText::setPosition(sf::Vector2f pos, bool rightAligned)
{
    m_image.setPosition(pos);
    setRightAligned(rightAligned);
}



void DrawableText::setDisplayedText(const char* text)
{
    m_image.setString(sf::String(text));
    realign();
}


void setDisplayedText(DrawableText& dt, const std::string& text)
{
    dt.setDisplayedText(text.c_str());
}

void setDisplayedNumber(DrawableText& dt, float value)
{
    std::string str;
    std::stringstream(str) << value;
    dt.setDisplayedText(str.c_str());
}

void setDisplayedNumber(DrawableText& dt, int value)
{
    std::string str;
    std::stringstream(str) << value;
    dt.setDisplayedText(str.c_str());
}


void DrawableText::realign()
{
    m_image.setOrigin(m_image.getLocalBounds().width, 0);
}


const sf::Drawable& DrawableText::sprite() const
{
    return m_image;
}

sf::Drawable& DrawableText::sprite()
{
    return m_image;
}


