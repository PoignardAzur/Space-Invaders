

#include "Straffer.h"


Straffer::Straffer(const Para& parameters, AbstractStraffAI* ai)
{
    set(ai);
    set(parameters);
}

void Straffer::set(const Para& parameters)
{
    set(parameters.normalSpeed, parameters.boostValue, parameters.boostValue, parameters.rightLimit);
}


Straffer::Straffer(AbstractStraffAI* ai, float normalSpeed, float boostValue, float leftLimit, float rightLimit)
{
    set(ai);
    set(normalSpeed, boostValue, leftLimit, rightLimit);
}

void Straffer::set(float normalSpeed, float boostValue, float leftLimit, float rightLimit)
{
    m_normalSpeed = normalSpeed;
    m_boostValue = boostValue;

    m_limitLeft = leftLimit;
    m_limitRight = rightLimit;
}

void Straffer::set(AbstractStraffAI* ai)
{
    m_ai = ai;
}
/*
void Straffer::setLeftLimit(float value);
void Straffer::setRightLimit(float value);
void Straffer::setNormalSpeed(float value);
*/
void Straffer::update(float ticks)
{
    if (m_ai->goLeftRight() > 0)
    {
        applySpeed(ticks);
        replaceObject();
    }

    if (m_ai->goLeftRight() < 0)
    {
        applySpeed(-ticks);
        replaceObject();
    }
}

void Straffer::applySpeed(float ticks)
{
    if (b_boostActive)
    moveLR(m_boostValue * ticks);

    else
    moveLR(m_normalSpeed * ticks);
}

void Straffer::replaceObject()
{
    if (leftPos() < m_limitLeft)
    moveLR(m_limitLeft - leftPos());

    else if (rightPos() > m_limitRight)
    moveLR(m_limitRight - rightPos());
}


float Straffer::boostValue()
{
	return m_boostValue;
}
/*
void Straffer::setBoostValue(float value)
{
	m_boostValue = value;
}
*/
bool Straffer::isBoostActivated()
{
	return b_boostActive;
}


void Straffer::startBoost()
{
	b_boostActive = true;
}

void Straffer::stopBoost()
{
	b_boostActive = true;
}

