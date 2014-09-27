


#include "NiveauShoot.h"


NiveauShoot::NiveauShoot(std::istream& flux, Entrees* entrees) : Niveau()
{
    attribuer(flux, entrees);
}

void NiveauShoot::attribuer(std::istream& flux, Entrees* entrees)
{
    m_tableauEnnemis = new TableauVart<Ennemi>;
    ajouter(m_tableauEnnemis);
    m_tableauTirsEnnemis = new TableauVart<Tir>;
    ajouter(m_tableauTirsEnnemis);
    m_tableauTirsAllies = new TableauVart<Tir>;
    ajouter(m_tableauTirsAllies);

    m_entrees = entrees;
    int tailleFlux = 0;

    if(true)
    {
        int positionCurseur = flux.tellg();
        flux.seekg(0, std::ios::end);
        tailleFlux = flux.tellg();
        flux.seekg(positionCurseur, std::ios::beg);
    }

    int nombreImages = 0;
    flux >> nombreImages;

    std::string chaineCle;
    std::string chaineAdresse;

    while(nombreImages --)
    {
        flux >> chaineCle;
        flux >> chaineAdresse;

        sf::Texture image;
        image.loadFromFile(chaineAdresse);

        m_tableauSprites[chaineCle] = Sprite(image);
    }

    flux >> manaMax;
    mana = manaMax;
    flux >> delai;

    while (flux.tellg() != tailleFlux)
    {
        GenerateurEnnemis generateur(flux, m_tableauSprites, *m_tableauTirsEnnemis);
        generateur.attribuer(*m_tableauEnnemis);
        m_generateurs.push_back(generateur);
    }
}

void NiveauShoot::MAJ()
{
    if (mana < manaMax)
    mana ++;

    if (delai)
    delai --;

    else
    {
        GenerateurEnnemis& generateurChoisi = m_generateurs[m_hasard( m_generateurs.size() )];

        if (mana >= generateurChoisi.manaNecessaire())
        {
            generateurChoisi.tirer(m_hasard);
            mana -= generateurChoisi.coutMana();
        }
    }
}


