

#ifndef HUD_HEADER
#define HUD_HEADER

#include "AbstractLevel.h"


template <typename In, typename LevelType = AbstractLevel<In> >
class AbstractHUD : public AbstractGameInterface<In>
{
    public :

    explicit AbstractHUD(LevelType* level = 0);
    void setLevel(LevelType* level);
    virtual ~AbstractHUD();

    virtual void drawIn(AbstractDrawer& window);
    virtual bool toDelete();
    virtual void setUserInputs(AbstractInputs*);

    virtual void update(const In& inputData);               // by default, In is the number of ticks since the last update
    virtual AbstractGameInterface<In>* toLoad();            // mostly for menus, when a sub-menu is opened ; used by MetaInterface objects ; returns nulptr by default


    protected :

    virtual void deleteLater();
    virtual AbstractInputs* getInputs();
    virtual const AbstractInputs* getInputs() const;

    virtual void drawIn(AbstractDrawer& window, LevelType* level) = 0;
    virtual const LevelType* level() const;

    private:

    LevelType* m_level;
};



template <typename In, typename LevelType>
AbstractHUD<In, LevelType>::AbstractHUD(LevelType* level) : m_level(level)
{

}

template <typename In, typename LevelType>
AbstractHUD<In, LevelType>::~AbstractHUD()
{
    if (m_level)
    delete m_level;
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::setLevel(LevelType* level)
{
    m_level = level;
}




template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::drawIn(AbstractDrawer& window)
{
    drawIn(window, m_level);
}

template <typename In, typename LevelType>
const LevelType* AbstractHUD<In, LevelType>::level() const
{
    return m_level;
}





template <typename In, typename LevelType>
bool AbstractHUD<In, LevelType>::toDelete()
{
    return m_level->toDelete();
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::setUserInputs(AbstractInputs* userInputs)
{
    m_level->setUserInputs(userInputs);
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::update(const In& inputData)
{
    m_level->update(inputData);
}



template <typename In, typename LevelType>
AbstractGameInterface<In>* AbstractHUD<In, LevelType>::toLoad()
{
    return m_level->toLoad();
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::deleteLater()
{
    m_level->deleteLater();
}


template <typename In, typename LevelType>
AbstractInputs* AbstractHUD<In, LevelType>::getInputs()
{
    return m_level->getInputs();
}


template <typename In, typename LevelType>
const AbstractInputs* AbstractHUD<In, LevelType>::getInputs() const
{
    return m_level->getInputs();
}






#endif // HUD_HEADER

