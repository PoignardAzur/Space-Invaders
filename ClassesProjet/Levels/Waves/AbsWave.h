

#ifndef ABSTRACT_WAVE_HEADER
#define ABSTRACT_WAVE_HEADER

#include "../../Enemies/ShootingEnemy.h"


class BasicSpaceLevel;


class AbsWave
{
    public :

    void setLevel(BasicSpaceLevel* l);   // The level in which enemies spawn
    virtual bool update(float dt) = 0;
    virtual bool isDone() const = 0;                // No more enemies can spawn


    protected :

    void spawn(Enemy* e);


    private :

    BasicSpaceLevel* m_level;
};


#endif // ABSTRACT_WAVE_HEADER
