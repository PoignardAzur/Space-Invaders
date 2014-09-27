

#include "Timer.h"


Timer::Timer(float tempsDepart, float tempsMax, bool razAuto) :
m_temps(tempsDepart), m_tempsMax(tempsMax), m_autoRaz(razAuto)
{

}

void Timer::setMaxTime(float nTemps)
{
    m_tempsMax = nTemps;
}

void Timer::setTime(float nTemps, bool limiter)
{
    if (!limiter || nTemps <= m_tempsMax)
    m_temps = nTemps;

    else
    nTemps = m_tempsMax;
}

void Timer::setTimeToMax()
{
    m_temps = m_tempsMax;
}

bool Timer::decrement(float ticks)
{
    if (m_temps)
    {
        if (ticks >= m_temps)
        m_temps -= ticks;

        else
        m_temps = 0;

        return !m_temps;
    }

/// else
    if (m_autoRaz)
    setTimeToMax();

    return false;
}

inline float Timer::maxTime() const
{
    return m_tempsMax;
}

inline float Timer::time() const
{
    return m_temps;
}



std::vector<bool> decrement(std::vector<Timer> tableau, float ticks)
{
    std::vector<bool> tableauRetour (tableau.size(), true);

    for (unsigned short i = 0; i < tableau.size(); ++i)
    {
        tableauRetour[i] = tableau[i].decrement(ticks);
    }

    return tableauRetour;
}




