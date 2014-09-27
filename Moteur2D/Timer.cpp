

#include "Timer.h"


Timer::Timer(float tempsDepart, float tempsMax, bool razAuto) :
m_temps(tempsDepart), m_autoRaz(razAuto)
{
    if (tempsMax)
    m_tempsMax = tempsMax;

    else
    m_tempsMax = tempsDepart;
}

Timer::Timer(const Timer& t) : m_temps(t.m_temps), m_tempsMax(t.m_tempsMax), m_autoRaz(t.m_autoRaz)
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

void Timer::resetTimeToMax()
{
    m_temps = m_tempsMax;
}

bool Timer::decrement(float ticks)
{
    if (m_temps)
    {
        if (ticks <= m_temps)
        m_temps -= ticks;

        else if (m_autoRaz)
        {
            resetTimeToMax();
            return true;
        }

        else
        m_temps = 0;

        return m_temps == 0;
    }

/// else
    return true;
}

/*inline*/ float Timer::maxTime() const
{
    return m_tempsMax;
}

/*inline*/ float Timer::time() const
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




