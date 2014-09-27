


#ifndef HEADER_FUSIL
#define HEADER_FUSIL

#include "Arme.h"
#include "Laser.h"
#include <istream>

struct ParametresFusil
{
    ParametresFusil();
    ParametresFusil(std::istream& flux);
    void attribuer(std::istream& flux);

    int cadenceTir;
    int munitionsMax;
    int munitions;
    int vitesseCharge;
};

class Fusil : public Arme<Tir>
{
    public :

    Fusil(const ParametresLaser& para, const ParaVart& paraobjet, const ParametresFusil& paraFusil);
    void attribuer(const ParametresLaser& para, const ParaVart& paraobjet, const ParametresFusil& paraFusil);
    void attribuer(TableauVart<Tir>& ncible);

    virtual void MAJ();
    virtual bool peutTirer();
    virtual void tirer(sf::Vector2f position);

    private :

    ParametresFusil m_paraFusil;
    int m_tempsDepuisDernierTir;

    ParametresLaser m_paraTir;
    ParaVart m_paraobjet;
};


#endif


