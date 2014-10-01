

#ifndef ABSTRACT_WAVE_HEADER
#define ABSTRACT_WAVE_HEADER

#include "../../Enemies/ShootingEnemy.h"


class BasicSpaceLevel;


class AbsWave
{
    public :

    virtual void setTarget(VartPusher<Enemy>* t);   // The level in which enemies spawn
    virtual bool update(float dt) = 0;

    virtual bool isDone() const = 0;     // No more enemies can spawn
    virtual ~AbsWave() {}

    protected :
    VartPusher<Enemy>* target();

    private :
    VartPusher<Enemy>* m_target;
};


#endif // ABSTRACT_WAVE_HEADER
