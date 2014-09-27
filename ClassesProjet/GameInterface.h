

#ifndef GAME_INTERFACE_HEADER
#define GAME_INTERFACE_HEADER


#define DEFAULT_FONT_NAME "Ressources/arial.ttf"

#include "MainDimensions.h"
#include "../Moteur2D/Graphic/Abstractions/AbstractInterface.h"
#include "../Moteur2D/Graphic/Sprite.h"
#include "../Moteur2D/Graphic/Text.h"


class GameInterface : public AbstractInterface
{
    public :

    GameInterface();

    void setLifeSprite(sf::Sprite s);
    void setScoreCounter(const sf::Font& f, sf::Color c = sf::Color::White);
    void setScoreCounter(const char* fontFile, sf::Color c = sf::Color::White);
    void drawIn(sf::RenderTarget&) const;
    void setRemainingLives(int nLives);
    void setScore(int nScore);


    private :

    sf::Text m_text;
    sf::Font m_font;
    Sprite m_spriteLife_1;
    Sprite m_spriteLife_2;
    Sprite m_spriteLife_3;

    int m_lives;
};




#endif


