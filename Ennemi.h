



#ifndef HEADER_ENNEMI
#define HEADER_ENNEMI

#include "Moteur2D/includes.h"


struct ParaEnnemi
{
    public :

    float vitesse;
    int vie;
    CtB::ParaVart parametres;

    ParaEnnemi(float nVitesse, int nVie, CtB::ParaVart& nParametres) : parametres(nParametres)
    {
        vitesse = nVitesse;
        vie = nVie;
    }
};


class Ennemi : public CtB::Vart
{
    public :

    Ennemi(const ParaEnnemi& para);
    Ennemi(const ParaEnnemi& para, sf::Vector2f position);

    void MAJ();
    void enleverVie(int quantite);

    private :

    int m_vie;
};



#endif
