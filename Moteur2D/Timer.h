


#ifndef HEADER_TIMER
#define HEADER_TIMER

#include <vector>

/*
A class for an in-game timer
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
    // returns true if the timer reached zero ; if m_autoReset is true and the time reached zero, it returns true then resets back to its max delay

/*    inline */float maxTime() const;
/*    inline */float time() const;

    protected :

    private :

    float m_temps;
    float m_tempsMax;

    bool m_autoReset;

};

std::vector<bool> decrement(std::vector<Timer> tableau, float ticks);





#endif


