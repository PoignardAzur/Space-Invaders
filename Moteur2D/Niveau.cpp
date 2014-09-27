

#include "Niveau.h"

// Fuuuuuuuuuuuuuuuuu


Niveau::Niveau() : m_tableau15(new TableauVart<VartAbs>())
{

}


void Niveau::MAJ()
{
    m_tableau15->MAJ();
}

void Niveau::afficherDans(AfficheurObjets& fenetre)
{
    m_tableau15->afficherDans(fenetre);
}



void Niveau::ajouter(VartAbs* ajout)
{
    if (m_tableau15)
    m_tableau15->ajouter(ajout);
}

bool Niveau::detruire() const
{
    return m_fin;
}


void Niveau::finirJeu()
{
    m_fin = true;
}

