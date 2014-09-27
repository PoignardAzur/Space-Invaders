

#include "Text.h"


DrawableText::DrawableText(const sf::Text& t, Alignement anchorPosition)
{
    set(t, anchorPosition);
}

DrawableText::DrawableText(const char* text, sf::Vector2f pos, const sf::Font& f, const sf::Color& c, Alignement anchorPosition)
{
    setPosition(pos);
    setFont(f);
    setColor(c);

    setDisplayedText(text);
    setAlignement(anchorPosition);
}

void DrawableText::set(const sf::Text& t, Alignement anchorPosition)
{
    m_image = t;
    setAlignement(anchorPosition);
}

void DrawableText::set(const char* text, sf::Vector2f pos, const sf::Font& f, const sf::Color& c, Alignement anchorPosition)
{
    setPosition(pos);
    setFont(f);
    setColor(c);

    setDisplayedText(text);
    setAlignement(anchorPosition);
}


void DrawableText::setAlignement(Alignement anchorPosition)
{
    m_anchorPosition = anchorPosition;
    realign();
}

void DrawableText::setFont(const sf::Font& f, int size)
{
    m_font = f;
    m_image.setFont(f);
    m_image.setCharacterSize(size);
}

void DrawableText::setColor(const sf::Color& c)
{
    m_image.setColor(c);
}

void DrawableText::setPosition(sf::Vector2f pos, Alignement anchorPosition)
{
    setPosition(pos);
    setAlignement(anchorPosition);
}

void DrawableText::setPosition(sf::Vector2f pos)
{
    m_image.setPosition(pos);
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


//    TopLeftCorner; MiddleTopSide; TopRightCorner; MiddleLeftSide; Center; MiddleRightSide; DownLeftCorner; MiddleDownSide; DownRightCorner;
void DrawableText::realign()
{
    float origin_x;
    float origin_y;

    if (m_anchorPosition == TopLeftCorner || m_anchorPosition == MiddleLeftSide || m_anchorPosition == DownLeftCorner)
    origin_x = 0;

    else if (m_anchorPosition == TopRightCorner || m_anchorPosition == MiddleRightSide || m_anchorPosition == DownRightCorner)
    origin_x = m_image.getLocalBounds().width;

    else
    origin_x = m_image.getLocalBounds().width / 2;


    if (m_anchorPosition == TopLeftCorner || m_anchorPosition == MiddleTopSide || m_anchorPosition == TopRightCorner)
    origin_y = 0;

    else if (m_anchorPosition == DownLeftCorner || m_anchorPosition == MiddleDownSide || m_anchorPosition == DownRightCorner)
    origin_y = m_image.getLocalBounds().height;

    else
    origin_y = m_image.getLocalBounds().height / 2;


    m_image.setOrigin(origin_x, origin_y);
}


void DrawableText::drawIn(AbstractDrawer& cible) const
{
    cible.draw(m_image);
}


