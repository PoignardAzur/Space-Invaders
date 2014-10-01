

#include "../BasicSpaceLevel.h"
#include "AbsWave.h"



void AbsWave::setTarget(VartPusher<Enemy>* t)
{
    m_target = t;
}


VartPusher<Enemy>* AbsWave::target()
{
    return m_target;
}



