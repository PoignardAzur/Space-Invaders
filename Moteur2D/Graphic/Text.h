

#ifndef DRAWABLE_TEXT_HEADER
#define DRAWABLE_TEXT_HEADER

#include "Drawable.h"
#include <sstream>



class DrawableText : public DrawableObject
{
    public :

    DrawableText(const sf::Text& t, bool rightAligned = false);
    DrawableText(const char* text = 0, sf::Vector2f pos = sf::Vector2f(0,0), const sf::Font& f = sf::Font::getDefaultFont(), const sf::Color& c = sf::Color::White, bool rightAligned = false);

    void set(const sf::Text& t, bool rightAligned = false);
    void set(const char* text, sf::Vector2f pos, const sf::Font& f = sf::Font::getDefaultFont(), const sf::Color& c = sf::Color::White, bool rightAligned = false);
    void setRightAligned(bool right = false);
    void setPosition(sf::Vector2f pos, bool rightAligned = false);
    void setFont(const sf::Font& f, int size = 1);
    void setColor(const sf::Color& c);

    void setDisplayedText(const char* text);


    protected :

    const sf::Drawable& sprite() const;
    sf::Drawable& sprite();
    void realign();


    private :

    sf::Text m_image;
    bool m_rightAligned;
};


void setDisplayedText(DrawableText& dt, const std::string& text);
void setDisplayedNumber(DrawableText& text, float value);
void setDisplayedNumber(DrawableText& text, int value);


#endif


