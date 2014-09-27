


#ifndef HEADER_GENERATEUR_ENNEMIS
#define HEADER_GENERATEUR_ENNEMIS

#include "Ennemi.h"
#include "Fusil.h"
#include "Moteur2D/Alea.h"

struct ParametresGeneration
{
    ParametresGeneration();
    ParametresGeneration(std::istream& flux);
    void attribuer(std::istream& flux);

    int limiteGauche;
    int limiteDroite;
    int coutMana;
    int manaNecessaire;
};


class GenerateurEnnemis : protected Emetteur<Ennemi>
{
    public :

    GenerateurEnnemis(std::istream& flux, std::map<std::string, Sprite>& tableauSprites, TableauVart<Tir>& tableauTirs);
    void attribuer(std::istream& flux, std::map<std::string, Sprite>& tableauSprites, TableauVart<Tir>& tableauTirs);
    void attribuer(TableauVart<Ennemi>& ncible);

    void tirer(Alea& hasard);
    int coutMana();
    int manaNecessaire();

    private :

    ParaVart m_paraEnnemi;
    ParametresGeneration m_parametres;

    bool creerFusil;
    ParametresLaser m_paraTir;
    ParaVart m_paraObjetTir;
    ParametresFusil m_paraFusil;

    TableauVart<Tir>* p_tableauTirs;
    void tirer(sf::Vector2f position);
};


/*
      |
      |
      V

Ordre de lecture

- ParaVart
>> Nom image
>> hitbox.top,left,height,width
>> vitesse.x,y

- ParametresGeneration
>> limiteGauche
>> limiteDroite
>> coutMana
>> manaNecessaire

X A une arme ? 0/1

Si oui ->
- ParametresLaser
>> incremetation
>> vitesseMax
>> degats
>> munitionsConsommees

- ParaVart tir
>> Nom image
>> hitbox.top,left,height,width
>> vitesse.x,y

- ParametresFusil
>> cadenceTir;
>> munitionsMax;
>> munitions;
>> vitesseCharge;

*/


#endif
