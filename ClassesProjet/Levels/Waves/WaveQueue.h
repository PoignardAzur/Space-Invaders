

#ifndef WAVE_QUEUE_HEADER
#define WAVE_QUEUE_HEADER

#include "AbsWave.h"
#include <queue>


class WaveQueue : public AbsWave
{
    public :

    WaveQueue(VartPusher<Enemy>* t);
    void setTarget(VartPusher<Enemy>* t);
    void addWave(AbsWave* wave);

    bool update(float dt);
    bool isDone() const;

    ~WaveQueue();


    private :

    std::queue<AbsWave*> m_waves;
};



#endif // WAVE_QUEUE_HEADER
