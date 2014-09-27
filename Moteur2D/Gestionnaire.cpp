

#include "Gestionnaire.h"



CtB::Gestionnaire::Gestionnaire(AfficheurObjets* cible, Entrees* entrees) :
m_fenetreCible(cible), m_entrees(entrees)
{

}

void CtB::Gestionnaire::MAJ()
{
    if (m_tableau15)
    m_tableau15->MAJ();
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

