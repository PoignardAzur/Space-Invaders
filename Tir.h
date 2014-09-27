


#ifndef HEADER_TIR
#define HEADER_TIR



#include "Moteur2D/Jeu/Vart.h"


class Tir : public Vart
{
    public :

    Tir(const ParaVart& paraobjet, sf::Vector2f position) :
    Vart(paraobjet, position) {}

    virtual float degats() = 0;

    virtual bool detruitApresImpact()
    {
        return true;
    }

};



#endif
