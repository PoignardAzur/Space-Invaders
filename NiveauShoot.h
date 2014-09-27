


#ifndef HEADER_NIVEAU_SHOOT
#define HEADER_NIVEAU_SHOOT

#include "Moteur2D/Niveau.h"
#include "GenerateurEnnemis.h"


class NiveauShoot : public Niveau
{
    public :

    NiveauShoot(std::istream& flux, Entrees* entrees);
    void attribuer(std::istream& flux, Entrees* entrees);

    void MAJ();

    private :

    unsigned int mana;
    unsigned int manaMax;
    unsigned int delai;

    std::vector<GenerateurEnnemis> m_generateurs;
    std::map<std::string, Sprite> m_tableauSprites;

    TableauVart<Ennemi>* m_tableauEnnemis;
    TableauVart<Tir>* m_tableauTirsEnnemis;
    TableauVart<Tir>* m_tableauTirsAllies;

    Alea m_hasard;
};


#endif

/*
- Nombre images
 # Nom image, adresse image
 # Nom image, adresse image
 # Nom image, adresse image

- Manamax
- Delai

# GenerateurEnnemis m_generateurPeons;
# GenerateurEnnemis m_generateurVoleurs;
# GenerateurEnnemis m_generateurBrutes;
# GenerateurEnnemis m_generateurBoostes;
# GenerateurEnnemis m_generateurRapides;
# GenerateurEnnemis m_generateurTireurs;

*/
