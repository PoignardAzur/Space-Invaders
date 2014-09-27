

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Level.h"
#include "Graphic/VoidDrawer.h"

/*
Classe gerant l'ensemble du jeu.
*/
/// TODO : mieux definir l'utilite de la classe.
class BlossClass
{
    public :

    BlossClass(Level* niveauJoue = 0, Inputs* tableauEntrees = 0, sf::RenderWindow* cible = 0);
    void set(Level* niveauJoue, Inputs* tableauEntrees, sf::RenderWindow* cible);

    virtual void update(float tickSize);
    virtual bool doContinue();

    protected :

    Inputs* windowInputs();
    Level* playedLevel();

    private :

    boost::shared_ptr<Level> m_niveauJoue; // has-a
    boost::shared_ptr<Inputs> m_entrees; // has-a
    boost::shared_ptr<AbstractDrawer> m_fenetre; // has-a
    sf::RenderWindow* m_cible; // use-a
};


#endif

