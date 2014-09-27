


#ifndef HEADER_TIMER
#define HEADER_TIMER

#include <vector>

/*
Un bete timer. Les prototypes parlent d'eux mêmes.
*/
class Timer
{
    public :

    Timer(float tempsDepart = 0, float tempsMax = 0, bool razAuto = true);

    void setMaxTime(float nTemps);
    void setTime(float nTemps, bool limiter = false);
    virtual void setTimeToMax();

    bool decrement(float ticks);

    inline float maxTime() const;
    inline float time() const;

    protected :

    private :

    float m_temps;
    float m_tempsMax;

    bool m_autoRaz;

};

std::vector<bool> decrement(std::vector<Timer> tableau, float ticks);





#endif


