

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE


#include "Interfaces/AbstractLevel.h"
#include "Graphic/ObjectDrawer.h"
#include <memory>

/*
Abstraction of a class with only one instance per program, that controls the entire game.
*/

template <typename In>
class GameController
{
    public :

    void set(AbstractInputs* userInputs, sf::RenderWindow* target);
    virtual void update(In inputData);
    virtual bool doContinue();


    protected :

    AbstractInputs* windowInputs();
    AbstractDrawer* renderingWindow();
    virtual AbstractGameInterface<In>* interface() = 0;


    private :

    std::shared_ptr<AbstractInputs> m_userInputs;     // has-a
    std::shared_ptr<AbstractDrawer> m_window;         // has-a
    sf::RenderWindow* m_renderWindow;                   // use-a
};





template <typename In>
void GameController<In>::set(AbstractInputs* userInputs, sf::RenderWindow* target)
{
    m_userInputs = std::shared_ptr<AbstractInputs>(userInputs);
    m_renderWindow = target;

    if (target)
    m_window = std::shared_ptr<AbstractDrawer>(new ObjectDrawer(target));
}



template <typename In>
void GameController<In>::update(In inputData)
{
    if (m_window)
    m_window->clear();

    interface()->update(inputData);

    if (m_window)
    interface()->drawIn(*m_window);

    if (m_userInputs)
    m_userInputs->update();
}



template <typename In>
AbstractDrawer* GameController<In>::renderingWindow()
{
    return m_window.get();
}



template <typename In>
AbstractInputs* GameController<In>::windowInputs()
{
    return m_userInputs.get();
}



template <typename In>
bool GameController<In>::doContinue()
{
    return ! windowInputs()->closeWindow() && ! interface()->toDelete();
}






#endif

