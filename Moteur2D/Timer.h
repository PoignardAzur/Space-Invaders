


#ifndef HEADER_TIMER
#define HEADER_TIMER

#include <vector>


class Chronometre
{
    public :

    Chronometre(int tempsDepart = 0, int tempsMax = 0, bool razAuto = true);

    void modifierTempsMax(int nTemps);
    void modifierTemps(int nTemps, bool limiter = false);
    virtual void razTemps();

    bool decrementer();

    inline int tempsMax() const;
    inline int temps() const;

    protected :

    private :

    int m_temps;
    int m_tempsMax;

    bool m_autoRaz;

};

std::vector<bool> decrementer(std::vector<Chronometre> tableau);





#endif


