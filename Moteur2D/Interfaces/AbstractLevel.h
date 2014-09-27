
#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "AbstractGameInterface.h"
#include <random>
#include <chrono>



inline auto epoch_to_now() -> decltype(std::chrono::system_clock::now().time_since_epoch())
{
    return std::chrono::system_clock::now().time_since_epoch();
}



template <typename I, typename L>
class AbstractHUD;


template <typename In>
class AbstractLevel : public AbstractGameInterface<In>
{
    public :

    AbstractLevel(unsigned int seed = epoch_to_now().count());
    AbstractLevel(std::seed_seq& seed);
    virtual ~AbstractLevel();

    virtual std::default_random_engine& randomGenerator();

    virtual void drawIn(AbstractDrawer& window) = 0;
    virtual void update(const In& inputData) = 0;

    virtual AbstractGameInterface<In>* toLoad();

    template <typename I, typename L>
    friend class AbstractHUD;


    private :

    std::default_random_engine m_randomGenerator;
};


template <typename In>
AbstractLevel<In>::AbstractLevel(unsigned int seed) : m_randomGenerator(seed)
{

}

template <typename In>
AbstractLevel<In>::AbstractLevel(std::seed_seq& seed) : m_randomGenerator(seed)
{

}

template <typename In>
AbstractLevel<In>::~AbstractLevel()
{

}


template <typename In>
std::default_random_engine& AbstractLevel<In>::randomGenerator()
{
    return m_randomGenerator;
}

template <typename In>
AbstractGameInterface<In>* AbstractLevel<In>::toLoad()
{
    return nullptr;
}




#include "AbstractHUD.h"



#endif

