

#ifndef SPACE_HUD_HEADER
#define SPACE_HUD_HEADER

#define LIFE_TEXTURE_NAME "life"
#define DEFAULT_FONT_NAME "Ressources/arial.ttf"

#include "../Moteur2D.h"
#include "BasicSpaceLevel.h"
#include "../MainDimensions.h"
#include "../../Moteur2D/Graphic/Text.h"


class SpaceHUD : public AbstractHUD<float, BasicSpaceLevel>
{
    public :

    SpaceHUD(BasicSpaceLevel* l);
    SpaceHUD(const sf::Font& f, sf::Color c = sf::Color::White, BasicSpaceLevel* l = nullptr);
    //void setLevel(BasicSpaceLevel* level);

    void setLifeSprite(sf::Sprite s);

    void setAllFonts(const sf::Font& f, sf::Color c = sf::Color::White);
    void setAllFonts(const char* fontFile, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const sf::Font& f, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const char* fontFile, sf::Color c = sf::Color::White);
    void setLifeCounterFont(const sf::Font& f, sf::Color c = sf::Color::White);
    void setLifeCounterFont(const char* fontFile, sf::Color c = sf::Color::White);
    void setGameOverTextFont(const sf::Font& f, sf::Color c = sf::Color::White);
    void setGameOverTextFont(const char* fontFile, sf::Color c = sf::Color::White);

    void update(const float& ticks);


    protected :

    void drawIn(AbstractDrawer& window,  BasicSpaceLevel* level);
    void drawHUD(AbstractDrawer& window);

    void setRemainingLives(int nLives);
    void setScore(int nScore);
    void gameOver();


    private :

    DrawableText m_scoreText;
    sf::Font m_scoreFont;

    DrawableText m_gameOverText;
    sf::Font m_gameOverFont;

    DrawableText m_livesNumberDisplay;
    sf::Font m_livesNumberFont;

    sf::Sprite m_spriteLife_1;
    sf::Sprite m_spriteLife_2;
    sf::Sprite m_spriteLife_3;

    int m_lives;
    int m_score;
    bool m_gameOver;
};




#endif // SPACE_HUD_HEADER

