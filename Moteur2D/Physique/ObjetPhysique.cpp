


#include "ObjetPhysique.h"



bool CtB::collision(const CtB::ObjetPhysique& objet1, const CtB::ObjetPhysique& objet2)
{
    CtB::ObjetPhysique& objetNC1 = const_cast<CtB::ObjetPhysique&>(objet1);
    CtB::ObjetPhysique& objetNC2 = const_cast<CtB::ObjetPhysique&>(objet2);

    objetNC1.aligner(false);
    objetNC2.aligner(false);

    bool retour = collision(objetNC1.m_boite, objetNC2.m_boite);

    objetNC1.aligner(true);
    objetNC2.aligner(true);

    return retour;
}


void CtB::ObjetPhysique::aligner(bool reset)
{
    if (!reset)
    m_boite.decaler(position());

    else
    m_boite.decaler(-position());
}

