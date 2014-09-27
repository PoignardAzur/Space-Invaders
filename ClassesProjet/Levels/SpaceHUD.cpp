

#include "SpaceHUD.h"

#define GAP_BETWEEN_LIFE_INDICATORS 10
#define HAUTEUR_HUD 75
#define BOTTOM_GAP 10
#define SIDE_GAP 10

#define SCORE_FONT_SIZE 30
#define LIFE_FONT_SIZE 30
#define GAME_OVER_FONT_SIZE 90


SpaceHUD::SpaceHUD(BasicSpaceLevel* level, const sf::Font* f, sf::Color c) : AbstractHUD<float, BasicSpaceLevel>(level)
{
    m_gameOver = false;
    m_score = 0;
    m_lives = 0;

    m_gameOverText.setString("Game Over");
    m_scoreDrawer = new Menu::Counter();
    m_scoreDrawer->setBounds(0, 99999);
    m_scoreDrawer->setRightAligned(true);
    m_scoreLabel.setItem(m_scoreDrawer, "Score :");
    m_scoreLabel.setAlignement(true, GAP_BETWEEN_LIFE_INDICATORS);

    m_livesDrawer.setBounds(3, 99);
    m_livesDrawer.setGaps(GAP_BETWEEN_LIFE_INDICATORS);
    m_livesDrawer.setRightAligned(false);

    setAllFonts(f, c);
}



void SpaceHUD::setLifeSprite(sf::Sprite s)
{
    m_livesDrawer.setSprite(s);
}


void SpaceHUD::setAllFonts(const sf::Font* f, sf::Color c)
{
    setScoreCounterFont(f, c);
    setLifeCounterFont(f, c);
    setGameOverTextFont(f, c);
}

void SpaceHUD::setScoreCounterFont(const sf::Font* f, sf::Color c)
{
    m_scoreDrawer->setFont(f, SCORE_FONT_SIZE);
    m_scoreDrawer->setColor(c);

    m_scoreLabel.setFont(f, LIFE_FONT_SIZE);
    m_scoreLabel.setColor(c);
}

void SpaceHUD::setScoreCounterFont(const sf::Font* f, sf::Color scoreColor, sf::Color labelColor)
{
    m_scoreDrawer->setFont(f, LIFE_FONT_SIZE);
    m_scoreDrawer->setColor(scoreColor);

    m_scoreLabel.setFont(f, LIFE_FONT_SIZE);
    m_scoreLabel.setColor(labelColor);
}

void SpaceHUD::setLifeCounterFont(const sf::Font* f, sf::Color c)
{
    m_livesDrawer.setFont(f, LIFE_FONT_SIZE);
    m_livesDrawer.setColor(c);
}

void SpaceHUD::setGameOverTextFont(const sf::Font* f, sf::Color c)
{
    m_gameOverText.setFont(f, GAME_OVER_FONT_SIZE);
    m_gameOverText.setColor(c);
}



void SpaceHUD::startGameOverMode()
{
    m_gameOver = true;
}


void SpaceHUD::update(const float& ticks)   // updates the level and measures its outputs
{
    AbstractHUD<float, BasicSpaceLevel>::update(ticks);     // this is what updates the level itself

    setRemainingLives( level()->lives() );
    setScore( level()->score() );

    if (level()->gameOver())
    startGameOverMode();
}



void SpaceHUD::drawHUD(AbstractDrawer& window)
{
    sf::RectangleShape r(sf::Vector2f(LARGEUR_FENETRE, HAUTEUR_HUD));
    r.setFillColor(sf::Color(128, 128, 128));
    window.draw(r);

    sf::FloatRect box(SIDE_GAP, 0, LARGEUR_FENETRE - 2 * SIDE_GAP, HAUTEUR_HUD - BOTTOM_GAP);
    m_livesDrawer.drawInBox(window, box, Menu::BottomLeftCorner);
    m_scoreLabel.drawInBox(window, box, Menu::BottomRightCorner);
}



void SpaceHUD::drawIn(AbstractDrawer& window, BasicSpaceLevel* level)
{
    window.clear();

    sf::RenderTexture texture;
    ObjectDrawer d(&texture);
    texture.create(LARGEUR_FENETRE, HAUTEUR_FENETRE - HAUTEUR_HUD);

    level->drawIn(window);

    if(m_gameOver)
    m_gameOverText.drawInBox(d, sf::FloatRect(0, 0, LARGEUR_FENETRE, 0.6 * HAUTEUR_FENETRE), Menu::Center);

    sf::Sprite spr(texture.getTexture());
    spr.setPosition(sf::Vector2f(0, HAUTEUR_FENETRE));
    spr.setScale(1, -1);
    window.draw(spr);

    drawHUD(window);
}


void SpaceHUD::setRemainingLives(int nLives)
{
    m_livesDrawer.setValue(nLives);
}

void SpaceHUD::setScore(int nScore)
{
    m_scoreDrawer->setValue(nScore);
}









