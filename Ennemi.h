


#ifndef HEADER_ENNEMI
#define HEADER_ENNEMI

#include "Tir.h"
#include "Arme.h"

class Ennemi : public Vart
{
    public :

    Ennemi(const ParaVart& paraobjet, sf::Vector2f position, Arme<Tir>* arme);
    void MAJ();

    private :

    boost::shared_ptr< Arme<Tir> > m_arme;
};



#endif

