

#include "ParametresVart.h"


CtB::Vart::Parametres::Parametres(ObjetAffichable* nsprite, ObjetPhysique* nhitbox) :
m_sprite(nsprite), m_hitbox(nhitbox)
{

}

CtB::ObjetAffichable* CtB::Vart::Parametres::sprite()
{
    return m_sprite;
}

CtB::ObjetPhysique* CtB::Vart::Parametres::hitbox()
{
    return m_hitbox;
}


