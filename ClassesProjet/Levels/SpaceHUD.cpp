

#include "SpaceHUD.h"




SpaceHUD::SpaceHUD(const sf::Font& f, sf::Color c, BasicSpaceLevel* level) : SpaceHUD(level)
{
    setAllFonts(f, c);
}

SpaceHUD::SpaceHUD(BasicSpaceLevel* level) : AbstractHUD<float, BasicSpaceLevel>(level)
{
    m_gameOverText.setDisplayedText("Game Over");
    m_gameOver = false;
    m_score = 0;
}



void SpaceHUD::setLifeSprite(sf::Sprite s)
{
    m_spriteLife_1 = s;
    m_spriteLife_2 = s;
    m_spriteLife_3 = s;

    m_spriteLife_1.setPosition(FIRST_LIFE_INDICATOR_POSITION);
    m_spriteLife_2.setPosition(SECOND_LIFE_INDICATOR_POSITION);
    m_spriteLife_3.setPosition(THIRD_LIFE_INDICATOR_POSITION);
}


void SpaceHUD::setAllFonts(const sf::Font& f, sf::Color c)
{
    setScoreCounterFont(f, c);
    setLifeCounterFont(f, c);
    setGameOverTextFont(f, c);
}

void SpaceHUD::setAllFonts(const char* fontFile, sf::Color c)
{
    setScoreCounterFont(fontFile, c);
    setLifeCounterFont(fontFile, c);
    setGameOverTextFont(fontFile, c);
}

void SpaceHUD::setScoreCounterFont(const sf::Font& f, sf::Color c)
{
    m_scoreFont = f;
    m_scoreText.setFont(m_scoreFont, 30);
    m_scoreText.setColor(c);
    m_scoreText.setPosition(SCORE_POSITION, TopRightCorner);
}

void SpaceHUD::setScoreCounterFont(const char* fontFile, sf::Color c)
{
    m_scoreFont.loadFromFile(fontFile);
    setScoreCounterFont(m_scoreFont, c);
}

void SpaceHUD::setLifeCounterFont(const sf::Font& f, sf::Color c)
{
    m_livesNumberFont = f;
    m_livesNumberDisplay.setFont(f, 30);
    m_livesNumberDisplay.setColor(c);
    m_livesNumberDisplay.setPosition(LIFE_NUMBER_INDICATOR_POSITION, DownLeftCorner);
}

void SpaceHUD::setLifeCounterFont(const char* fontFile, sf::Color c)
{
    m_livesNumberFont.loadFromFile(fontFile);
    setLifeCounterFont(m_livesNumberFont, c);
}

void SpaceHUD::setGameOverTextFont(const sf::Font& f, sf::Color c)
{
    m_gameOverFont = f;
    m_gameOverText.setFont(m_gameOverFont, 90);

    m_gameOverText.setColor(c);
    m_gameOverText.setPosition(GAME_OVER_TEXT_POSITION, MiddleDownSide);
}


void SpaceHUD::setGameOverTextFont(const char* fontFile, sf::Color c)
{
    m_gameOverFont.loadFromFile(fontFile);
    setGameOverTextFont(m_gameOverFont, c);
}


void SpaceHUD::gameOver()
{
    m_gameOver = true;
}


void SpaceHUD::update(const float& ticks)   // updates the level and measures its outputs
{
    AbstractHUD<float, BasicSpaceLevel>::update(ticks);     // this is what updates the level itself

    setRemainingLives( level()->lives() );
    setScore( level()->score() );

    if (level()->gameOver())
    gameOver();
}



void SpaceHUD::drawHUD(AbstractDrawer& window)
{
    sf::RectangleShape r(sf::Vector2f(LARGEUR_FENETRE, HAUTEUR_HUD));
    r.setFillColor(sf::Color(128, 128, 128));
    window.draw(r);

    if (m_lives >= 1)
    window.draw(m_spriteLife_1);

    if (m_lives == 2 || m_lives == 3)
    window.draw(m_spriteLife_2);

    if (m_lives == 3)
    window.draw(m_spriteLife_3);

    if (m_lives > 3)
    {
        std::stringstream sstr;
        sstr << "x" << m_lives;
        m_livesNumberDisplay.setDisplayedText(sstr.str().c_str());

        window.draw(m_livesNumberDisplay);
    }

    //    setDisplayedNumber(m_scoreText, nScore);
    std::stringstream sstr;
    sstr << m_score;
    m_scoreText.setDisplayedText(sstr.str().c_str());
    window.draw(m_scoreText);
}



void SpaceHUD::drawIn(AbstractDrawer& window, BasicSpaceLevel* level)
{
    window.clear();

    sf::RenderTexture texture;
    ObjectDrawer d(&texture);
    texture.create(LARGEUR_FENETRE, HAUTEUR_FENETRE - HAUTEUR_HUD);

    level->drawIn(window);

    if(m_gameOver)
    m_gameOverText.drawIn(d);

    sf::Sprite spr(texture.getTexture());
    spr.setPosition(sf::Vector2f(0, HAUTEUR_FENETRE));
    spr.setScale(1, -1);
    window.draw(spr);

    drawHUD(window);
}


void SpaceHUD::setRemainingLives(int nLives)
{
    m_lives = nLives;
}

void SpaceHUD::setScore(int nScore)
{
    m_score = nScore;
}









