

#ifndef HEADER_NIVEAU
#define HEADER_NIVEAU

#include "Entries/InputsArray.h"
#include "Graphic/Abstractions/AbstractDrawer.h"
#include "Game/VartArray.h"
#include "../SQLite/statement.hpp"
#include <sstream>
#include <string>

/*
Gere le deroulement d'un niveau, ses differents composants.
*/
template <typename In, typename Out>
class Level
{
    public :

    virtual void attribuer(Inputs* entrees);
  //  virtual void attribuer(sql3::Statement& data) = 0;

    virtual void update(const In& inputData) = 0;
    virtual const Out& outputData() const = 0;
    virtual void drawIn(AbstractDrawer& fenetre) = 0;


    protected :

    Inputs* m_entrees; // use-a

};


template <typename In, typename Out>
void Level<In,Out>::attribuer(Inputs* entrees)
{
    m_entrees = entrees;
}

/*    virtual void finirJeu(); // met la valeur de detruire() à true;
    void add(AbsVart* ajout); // ajouter un objet dans le niveau. Uniquement pour l'initialisation (tableaux et objets de debut de niveau)
    void clear();

    private :

    boost::shared_ptr< VartArray<AbsVart> > m_tableau15; // has-a
    bool m_fin;
*/



#endif

