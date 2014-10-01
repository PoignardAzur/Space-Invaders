

#include "WaveQueue.h"


WaveQueue::WaveQueue(VartPusher<Enemy>* t)
{
    setTarget(t);
}

void WaveQueue::setTarget(VartPusher<Enemy>* t)
{
        if (!m_waves.empty())
        m_waves.front()->setTarget(target());
}

void WaveQueue::addWave(AbsWave* wave)
{
    wave->setTarget(target());
    m_waves.push(wave);
}

bool WaveQueue::update(float dt)
{
    if (!m_waves.empty())
    {
        m_waves.front()->update(dt);

        if (m_waves.front()->isDone())
        {
            delete m_waves.front();
            m_waves.pop();

            if (!m_waves.empty())
            m_waves.front()->setTarget(target());
        }
    }

    return isDone();
}

bool WaveQueue::isDone() const
{
    return m_waves.empty();
}

WaveQueue::~WaveQueue()
{
    while (!m_waves.empty())
    {
        delete m_waves.front();
        m_waves.pop();
    }
}
