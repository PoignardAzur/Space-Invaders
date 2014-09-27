
#ifndef ABSTRACT_GAME_INTERFACE_HEADER
#define ABSTRACT_GAME_INTERFACE_HEADER

#include "../Entries/InputsArray.h"
#include "../Graphic/AbstractDrawer.h"


template <typename In>
class AbstractGameInterface
{
    public :

    AbstractGameInterface() { m_deleteLater = false; }
    virtual ~AbstractGameInterface() {}

    virtual void drawIn(AbstractDrawer& window) = 0;
    virtual bool toDelete() const;                      // is this returns true, the object must be deleted (mainly used in the main class and in MetaInterface objects
    virtual void setUserInputs(AbstractInputs*);

    virtual void update(const In& inputData) = 0;       // by default, In is the number of ticks since the last update
    virtual AbstractGameInterface* toLoad() = 0;            // mostly for menus, when a sub-menu is opened ; used by MetaInterface objects ; returns nulptr by default

    protected :

    virtual void deleteLater();
    virtual AbstractInputs* getInputs();
    virtual const AbstractInputs* getInputs() const;

    private :

    bool m_deleteLater;
    AbstractInputs* m_inputs; // use-a
};



template <typename In>
bool AbstractGameInterface<In>::toDelete() const
{
    return m_deleteLater;
}

template <typename In>
void AbstractGameInterface<In>::deleteLater()
{
    m_deleteLater = true;
}


template <typename In>
void AbstractGameInterface<In>::setUserInputs(AbstractInputs* newInputs)
{
    m_inputs = newInputs;
}



template <typename In>
AbstractInputs* AbstractGameInterface<In>::getInputs()
{
    return m_inputs;
}


template <typename In>
const AbstractInputs* AbstractGameInterface<In>::getInputs() const
{
    return const_cast<AbstractGameInterface*>(this)->getInputs();
}


#endif


