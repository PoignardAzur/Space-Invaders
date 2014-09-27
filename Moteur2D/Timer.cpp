

#include "Timer.h"


CtB::Chronometre::Chronometre(int tempsDepart, int tempsMax, bool razAuto) :
m_temps(tempsDepart), m_tempsMax(tempsMax), m_autoRaz(razAuto)
{

}

void CtB::Chronometre::modifierTempsMax(int nTemps)
{
    m_tempsMax = nTemps;
}

void CtB::Chronometre::modifierTemps(int nTemps, bool limiter)
{
    if (!limiter || nTemps <= m_tempsMax)
    m_temps = nTemps;

    else
    nTemps = m_tempsMax;
}

void CtB::Chronometre::razTemps()
{
    m_temps = m_tempsMax;
}

bool CtB::Chronometre::decrementer()
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

inline int CtB::Chronometre::tempsMax() const
{
    return m_tempsMax;
}

inline int CtB::Chronometre::temps() const
{
    return m_temps;
}



std::vector<bool> CtB::decrementer(std::vector<Chronometre> tableau)
{
    std::vector<bool> tableauRetour (tableau.size(), true);

    for (unsigned short i = 0; i < tableau.size(); ++i)
    {
        tableauRetour[i] = tableau[i].decrementer();
    }

    return tableauRetour;
}




