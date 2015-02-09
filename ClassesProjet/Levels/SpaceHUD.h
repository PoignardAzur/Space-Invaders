

#ifndef SPACE_HUD_HEADER
#define SPACE_HUD_HEADER

#define LIFE_TEXTURE_NAME "life"

#include "../Moteur2D.h"
#include "BasicSpaceLevel.h"
#include "../MainDimensions.h"


class SpaceHUD
{
    public :

    SpaceHUD(const sf::Font* f = nullptr, sf::Color c = sf::Color::White);
    void setLifeSprite(sf::Sprite s);
    void setAllFonts(const sf::Font* f, sf::Color c = sf::Color::White);

    void setLifeCounterFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setGameOverTextFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const sf::Font* f, sf::Color scoreColor, sf::Color labelColor);

    void updateFrom(BasicSpaceLevel* level);
    void drawIn(AbstractDrawer& window,  BasicSpaceLevel* level);


    protected :

    void setRemainingLives(int nLives);
    void setScore(int nScore);


    private :

    Menu::Text m_gameOverText;
    Menu::LifeCounter m_livesDrawer;

    Menu::Label m_scoreLabel;
    Menu::Counter* m_scoreDrawer;

    int m_lives;
    int m_score;
    bool m_gameOver;
    bool m_isComplete;
};




#endif // SPACE_HUD_HEADER

