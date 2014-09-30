

#include "../BasicSpaceLevel.h"
#include "AbsWave.h"



void AbsWave::setLevel(BasicSpaceLevel* l)
{
    m_level = l;
}


void AbsWave::spawn(Enemy* e)
{
    m_level->enemies()->add(e);
}



