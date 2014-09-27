

#ifndef HEADER_LASER
#define HEADER_LASER

#include "Tir.h"



struct ParametresLaser
{
    public :

    ParametresLaser();
    ParametresLaser(std::istream& flux);
    void attribuer(std::istream& flux);

    float incremetation;
    float vitesseMax;
    int degats;
    int munitionsConsommees;
};


class Laser : public Tir
{
    public :

    Laser(const ParametresLaser& para, const ParaVart& paraobjet, sf::Vector2f position);
    float degats();
    void MAJ();

    private :
    ParametresLaser m_para;
};

#endif

