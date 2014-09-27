

#include "GenerateurEnnemis.h"


ParametresGeneration::ParametresGeneration()
{

}

ParametresGeneration::ParametresGeneration(std::istream& flux)
{
    attribuer(flux);
}

void ParametresGeneration::attribuer(std::istream& flux)
{
    flux >> limiteGauche;
    flux >> limiteDroite;
    flux >> coutMana;
    flux >> manaNecessaire;
}

GenerateurEnnemis::GenerateurEnnemis(std::istream& flux, std::map<std::string, Sprite>& tableauSprites, TableauVart<Tir>& tableauTirs)
{
    attribuer(flux, tableauSprites, tableauTirs);
}


void GenerateurEnnemis::attribuer(TableauVart<Ennemi>& ncible)
{
    Emetteur<Ennemi>::attribuer(ncible);
}



void GenerateurEnnemis::attribuer(std::istream& flux, std::map<std::string, Sprite>& tableauSprites, TableauVart<Tir>& tableauTirs)
{
    m_paraEnnemi.attribuer(flux, tableauSprites);
    m_parametres.attribuer(flux);

    int boolArme;
    flux >> boolArme;

    if (boolArme)
    {
        m_paraTir.attribuer(flux);
        m_paraObjetTir.attribuer(flux, tableauSprites);
        m_paraFusil.attribuer(flux);
        creerFusil = true;
    }

    else
    creerFusil = false;
}

void GenerateurEnnemis::tirer(Alea& hasard)
{
    const sf::IntRect& boite = m_paraEnnemi.hitbox();

    float abscisse = hasard( m_parametres.limiteGauche - boite.left, m_parametres.limiteDroite - boite.left - boite.width );

    tirer(sf::Vector2f(abscisse, - boite.top - boite.height));
}

void GenerateurEnnemis::tirer(sf::Vector2f position)
{
    Fusil* pointeurFusil = 0;

    if (creerFusil)
    {
        pointeurFusil = new Fusil(m_paraTir, m_paraObjetTir, m_paraFusil);
        pointeurFusil->attribuer(*p_tableauTirs);
    }

    cible().ajouter(new Ennemi(m_paraEnnemi, position, pointeurFusil));
}

int GenerateurEnnemis::coutMana()
{
    return m_parametres.coutMana;
}

int GenerateurEnnemis::manaNecessaire()
{
    return m_parametres.manaNecessaire;
}


