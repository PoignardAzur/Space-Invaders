



#ifndef HEADER_VAISSEAU
#define HEADER_VAISSEAU

#include "Moteur2D/includes.h"
#include "Tir.h"

#define LIMITE_GAUCHE 0
#define LIMITE_DROITE 200


class Vaisseau : public CtB::Vart
{
    public :

    Vaisseau(const CtB::ParaVart& paraVaisseau, const ParaTir& paraTirs, CtB::TableauVart<Tir>* tableau, int cadenceTir);

    void tirer();
    void deplacer(int distance, bool relatif = true);
    void MAJ();


    private :

    ParaTir m_paraTirs;
    int m_cadence;
    int m_munitions;

    CtB::TableauVart<Tir>* m_tableau;
};



#endif


