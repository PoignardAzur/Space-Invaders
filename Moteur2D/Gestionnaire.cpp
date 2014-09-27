

#include "Gestionnaire.h"



CtB::Gestionnaire::Gestionnaire(AfficheurObjets* cible, Entrees* entrees) :
m_fenetreCible(cible), m_tableau15(new TableauVart<VartAbs>()), m_entrees(entrees)
{

}

void CtB::Gestionnaire::MAJ()
{
    if (m_entrees)
    m_entrees->MAJ();

    m_fenetreCible->effacer();

    if (m_tableau15)
    {
        m_tableau15->MAJ();
        m_tableau15->afficherDans(*m_fenetreCible);
    }

    m_fenetreCible->afficherTout();
}

void CtB::Gestionnaire::ajouter(VartAbs* ajout)
{
    if (m_tableau15)
    m_tableau15->ajouter(ajout);
}

CtB::Entrees& CtB::Gestionnaire::entreesFenetre()
{
    return *m_entrees;
}


bool CtB::Gestionnaire::finDuJeu() const
{
    return m_entrees->fini() || m_fin;
}


void CtB::Gestionnaire::finirJeu()
{
    m_fin = true;
}

