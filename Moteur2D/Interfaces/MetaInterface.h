


#ifndef META_INTERFACE_HEADER
#define META_INTERFACE_HEADER

#include "AbstractGameInterface.h"
#include <vector>
#include <stack>


template <typename In>
class MetaInterface : public AbstractGameInterface<In>     // abstract class
{
    typedef AbstractGameInterface<In> AGIi;

    public :

    ~MetaInterface();
    void drawIn(AbstractDrawer& window);
    void update(const In& inputData);
    void addInterface(AGIi* newInterface);

    virtual AbstractGameInterface<In>* toLoad();

    protected :

    AGIi* currentInterface();
    const AGIi* currentInterface() const;

    private :

    std::stack<AGIi*> m_interfaces;        // has-a
};



template <typename In>
void MetaInterface<In>::drawIn(AbstractDrawer& window)
{
    currentInterface()->drawIn(window);
}



template <typename In>
void MetaInterface<In>::update(const In& inputData)
{
    currentInterface()->update(inputData);

    if (currentInterface()->toLoad())
    {
        addInterface(currentInterface()->toLoad());
    }

    if (currentInterface()->toDelete())
    {
        AGIi* lastInterface = currentInterface();
        m_interfaces.pop();

        if (! m_interfaces.size())
        AbstractGameInterface<In>::deleteLater();

        delete lastInterface;
    }
}


template <typename In>
void MetaInterface<In>::addInterface(AGIi* newInterface)
{
    m_interfaces.push(newInterface);
}


template <typename In>
AbstractGameInterface<In>* MetaInterface<In>::currentInterface()
{
    return m_interfaces.top();
}


template <typename In>
const AbstractGameInterface<In>* MetaInterface<In>::currentInterface() const
{
    return m_interfaces.top();
}


template <typename In>
AbstractGameInterface<In>* MetaInterface<In>::toLoad()
{
    return nullptr;
}



template <typename In>
MetaInterface<In>::~MetaInterface()
{
    while(m_interfaces.size())
    {
        delete m_interfaces.top();
        m_interfaces.pop();
    }
}


#endif
