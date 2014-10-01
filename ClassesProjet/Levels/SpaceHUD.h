

#ifndef SPACE_HUD_HEADER
#define SPACE_HUD_HEADER

#define LIFE_TEXTURE_NAME "life"
#define DEFAULT_FONT_NAME "Ressources/arial.ttf"

#include "../Moteur2D.h"
#include "BasicSpaceLevel.h"
#include "../MainDimensions.h"


class SpaceHUD : public AbstractHUD<float, BasicSpaceLevel>
{
    public :

    SpaceHUD(BasicSpaceLevel* l /*= nullptr*/, const sf::Font* f = nullptr, sf::Color c = sf::Color::White);
    //void setLevel(BasicSpaceLevel* level);

    void setLifeSprite(sf::Sprite s);

    void setAllFonts(const sf::Font* f, sf::Color c = sf::Color::White);
    void setLifeCounterFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setGameOverTextFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const sf::Font* f, sf::Color c = sf::Color::White);
    void setScoreCounterFont(const sf::Font* f, sf::Color scoreColor, sf::Color labelColor);

    void update(const float& ticks);


    protected :

    void drawIn(AbstractDrawer& window,  BasicSpaceLevel* level);
    void drawHUD(AbstractDrawer& window);

    void setRemainingLives(int nLives);
    void setScore(int nScore);
    void startGameOverMode();


    private :

    Menu::Text m_gameOverText;
    Menu::LifeCounter m_livesDrawer;

    Menu::Label m_scoreLabel;
    Menu::Counter* m_scoreDrawer;

    int m_lives;
    int m_score;
    bool m_gameOver;
};




#endif // SPACE_HUD_HEADER

