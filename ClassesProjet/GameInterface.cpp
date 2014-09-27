


#include "GameInterface.h"
#include <sstream>
#include <cassert>


GameInterface::GameInterface()
{
    m_text.setCharacterSize(30);
}


void GameInterface::setLifeSprite(sf::Sprite s)
{
    m_spriteLife_1.set(s);
    m_spriteLife_2.set(s);
    m_spriteLife_3.set(s);

    m_spriteLife_1.setPosition(FIRST_LIFE_INDICATOR_POSITION);
    m_spriteLife_2.setPosition(SECOND_LIFE_INDICATOR_POSITION);
    m_spriteLife_3.setPosition(THIRD_LIFE_INDICATOR_POSITION);
}

void GameInterface::setScoreCounter(const sf::Font& f, sf::Color c)
{
    m_font = f;
    m_text.setFont(m_font);

    m_text.setColor(c);
    m_text.setPosition(SCORE_POSITION);
}

void GameInterface::setScoreCounter(const char* fontFileName, sf::Color c)
{
    m_font.loadFromFile(fontFileName);
    m_text.setFont(m_font);
    m_text.setColor(c);
    m_text.setPosition(SCORE_POSITION);
}

void GameInterface::drawIn(sf::RenderTarget& t) const
{
    if (m_lives >= 1)
    drawObjectIn(m_spriteLife_1, t);
    if (m_lives >= 2)
    drawObjectIn(m_spriteLife_2, t);
    if (m_lives >= 3)
    drawObjectIn(m_spriteLife_3, t);

    t.draw(m_text);
}

void GameInterface::setRemainingLives(int nLives)
{
    m_lives = nLives;
}

void GameInterface::setScore(int nScore)
{
//    setDisplayedNumber(m_text, nScore);
    std::stringstream sstr;
    sstr << nScore;
    m_text.setString(sstr.str());
    m_text.setOrigin(m_text.getGlobalBounds().width, 0);

    assert(sstr.str() != "");
}

