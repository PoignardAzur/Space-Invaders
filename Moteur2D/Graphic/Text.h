

#ifndef DRAWABLE_TEXT_HEADER
#define DRAWABLE_TEXT_HEADER

#include "AbstractDrawable.h"
#include <sstream>


enum Alignement
{
    TopLeftCorner, MiddleTopSide, TopRightCorner, MiddleLeftSide, Center, MiddleRightSide, DownLeftCorner, MiddleDownSide, DownRightCorner
};



class DrawableText : public AbstractDrawable
{
    public :

    DrawableText(const sf::Text& t, Alignement anchorPosition = TopLeftCorner);
    DrawableText(const char* text = nullptr, sf::Vector2f pos = sf::Vector2f(0,0), const sf::Font& f = sf::Font(), const sf::Color& c = sf::Color::White, Alignement anchorPosition = TopLeftCorner);

    void set(const sf::Text& t, Alignement anchorPosition = TopLeftCorner);
    void set(const char* text, sf::Vector2f pos, const sf::Font& f = sf::Font(), const sf::Color& c = sf::Color::White, Alignement anchorPosition = TopLeftCorner);
    void setAlignement(Alignement anchorPosition);
    void setPosition(sf::Vector2f pos, Alignement anchorPosition);
    void setPosition(sf::Vector2f pos);
    void setFont(const sf::Font& f, int size = 1);
    void setColor(const sf::Color& c);

    void setDisplayedText(const char* text);

    virtual void drawIn(AbstractDrawer& cible) const;


    protected :
    void realign();


    private :

    sf::Text m_image;
    sf::Font m_font;
    Alignement m_anchorPosition;
};


void setDisplayedText(DrawableText& dt, const std::string& text);
void setDisplayedNumber(DrawableText& text, float value);
void setDisplayedNumber(DrawableText& text, int value);


#endif


