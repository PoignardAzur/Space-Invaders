



#ifndef HEADER_TIR
#define HEADER_TIR

#include "Moteur2D/includes.h"


struct ParaTir
{
    public :

    float vitesseMax;
    float acceleration;
    CtB::ParaVart parametres;

    ParaTir(float nVitesseMax, float nAcceleration, const CtB::ParaVart& nParametres);
};


class Tir : public CtB::Vart
{
    public :

    Tir(const ParaTir& para);
    Tir(const ParaTir& para, sf::Vector2f position);

    void MAJ();

    private :

    float m_vitesseMax;
    float m_acceleration;
};

#endif
