

#include "Timer.h"


Chronometre::Chronometre(int tempsDepart, int tempsMax, bool razAuto) :
m_temps(tempsDepart), m_tempsMax(tempsMax), m_autoRaz(razAuto)
{

}

void Chronometre::modifierTempsMax(int nTemps)
{
    m_tempsMax = nTemps;
}

void Chronometre::modifierTemps(int nTemps, bool limiter)
{
    if (!limiter || nTemps <= m_tempsMax)
    m_temps = nTemps;

    else
    nTemps = m_tempsMax;
}

void Chronometre::razTemps()
{
    m_temps = m_tempsMax;
}

bool Chronometre::decrementer()
{
    if (m_temps)
    {
        m_temps --;
        return !m_temps;
    }

/// else
    if (m_autoRaz)
    razTemps();

    return false;
}

inline int Chronometre::tempsMax() const
{
    return m_tempsMax;
}

inline int Chronometre::temps() const
{
    return m_temps;
}



std::vector<bool> decrementer(std::vector<Chronometre> tableau)
{
    std::vector<bool> tableauRetour (tableau.size(), true);

    for (unsigned short i = 0; i < tableau.size(); ++i)
    {
        tableauRetour[i] = tableau[i].decrementer();
    }

    return tableauRetour;
}




