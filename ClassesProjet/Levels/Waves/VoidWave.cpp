

#include "VoidWave.h"


VoidWave::VoidWave(float length)
{
    setLength(length);
}

void VoidWave::setLength(float l)
{
    m_length = l;
}

bool VoidWave::update(float dt)
{
    if (m_length > 0)
    m_length -= dt;

    return (m_length > 0);
}

bool VoidWave::isDone() const
{
    return (m_length > 0);
}



