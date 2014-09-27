

#ifndef HEADER_NIVEAU
#define HEADER_NIVEAU

#include "Entries/InputsArray.h"
#include "Graphic/Abstractions/AbstractDrawer.h"
#include "Game/VartArray.h"
#include <sstream>
#include <string>

/*
Gere le deroulement d'un niveau, ses differents composants.
*/
class Level //: public Majable
{
    public :

    Level();

    virtual void attribuer(Inputs* entrees); // remplacer par une abstraction, une interface

    virtual void update(float tickSize); // classique
    virtual bool deleteLevel() const; /* quand le niveau est fini, évidemment */ /// TODO : prévoir un mécanisme de sorties pour le niveau
    virtual void drawIn(AbstractDrawer& fenetre); // chacune des trois fonctions sont celles des Vart, elles sont donc majoritairement répercutées


    protected :
    virtual void finirJeu(); // met la valeur de detruire() à true;
    Inputs* m_entrees; // use-a
    public : void add(AbsVart* ajout); // ajouter un objet dans le niveau. Uniquement pour l'initialisation (tableaux et objets de debut de niveau)
    void clear();

    private :

    boost::shared_ptr< VartArray<AbsVart> > m_tableau15; // has-a
    bool m_fin;

/*
    friend class boost::serialization::access;

    template <typename Flux>
    void serialize(Flux& f, const unsigned long int version);
};


template <typename Flux>
void Niveau::serialize(Flux& f, const unsigned long int version)
{
    f & m_tableau15;
}*/};



#endif

