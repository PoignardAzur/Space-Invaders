
#ifndef VOID_WAVE_HEADER
#define VOID_WAVE_HEADER

#include "AbsWave.h"

class VoidWave : public AbsWave
{
    public :

    VoidWave(float length = 0);
    void setLength(float l);

    bool update(float dt);
    bool isDone() const;


    private :

    float m_length;
};


#endif // VOID_WAVE_HEADER
