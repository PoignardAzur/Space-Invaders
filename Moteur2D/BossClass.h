

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Level.h"
#include "Graphic/VoidDrawer.h"

/*
Classe gerant l'ensemble du jeu, et la transition entre les niveaux.
*/

template <typename In, typename Out>
class BlossClass
{
    public :

    void set(Inputs* tableauEntrees, sf::RenderWindow* cible);
    virtual void update(In tickSize);
    virtual bool doContinue();

    protected :

    Inputs* windowInputs();
    AbstractDrawer* renderingWindow();
    virtual Level<In, Out>* playedLevel() = 0;

    private :

    boost::shared_ptr<Inputs> m_entrees; // has-a
    boost::shared_ptr<AbstractDrawer> m_fenetre; // has-a
    sf::RenderWindow* m_cible; // use-a
};



template <typename In, typename Out>
void BlossClass<In, Out>::set(Inputs* tableauEntrees, sf::RenderWindow* cible)
{
    m_entrees = boost::shared_ptr<Inputs>(tableauEntrees);
    m_cible = cible;

    if (cible)
    m_fenetre = boost::shared_ptr<AbstractDrawer>(new ObjectDrawer(cible));
    else
    m_fenetre = boost::shared_ptr<VoidDrawer>();
//    m_fenetre = boost::shared_ptr<AfficheurObjetsAbstrait>(new AfficheurObjetsAbstrait);
}


template <typename In, typename Out>
void BlossClass<In, Out>::update(In tickSize)
{
    m_fenetre->clear();
    playedLevel()->update(tickSize);
    playedLevel()->drawIn(*m_fenetre);

    if (m_cible)
    m_cible->display();
    m_entrees->update();
}


template <typename In, typename Out>
AbstractDrawer* BlossClass<In, Out>::renderingWindow()
{
    return m_fenetre.get();
}


template <typename In, typename Out>
Inputs* BlossClass<In, Out>::windowInputs()
{
    return m_entrees.get();
}


template <typename In, typename Out>
bool BlossClass<In, Out>::doContinue()
{
    return windowInputs()->endGame();
}


#endif

