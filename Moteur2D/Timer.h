


#ifndef HEADER_TIMER
#define HEADER_TIMER

#include <vector>

/*
Un bete timer. Les prototypes parlent d'eux mêmes.
*/
class Timer
{
    public :

    Timer(float startTime = 0, float maxTime = 0, bool autoReset = false);
    Timer(const Timer& t);

    void setMaxTime(float nTime);
    void setTime(float nTime, bool limiter = false);
    virtual void resetTimeToMax();

    bool decrement(float ticks);

/*    inline */float maxTime() const;
/*    inline */float time() const;

    protected :

    private :

    float m_temps;
    float m_tempsMax;

    bool m_autoRaz;

};

std::vector<bool> decrement(std::vector<Timer> tableau, float ticks);





#endif


