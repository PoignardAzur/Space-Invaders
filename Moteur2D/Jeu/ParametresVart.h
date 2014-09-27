
#ifndef HEADER_PARAMETRES_VART
#define HEADER_PARAMETRES_VART


#include "Vart.h"


namespace CtB
{

    class ParaVart
    {
        public :

        ParaVart(pSpr nsprite, const ObjetPhysique& nhitbox) :
        m_sprite(nsprite), m_hitbox(nhitbox)
        {

        }

        Sprite sprite() const
        {
            return m_sprite;
        }

        ObjetPhysique hitbox() const
        {
            return m_hitbox;
        }

        private :

        Sprite m_sprite;
        ObjetPhysique m_hitbox;
    };


}

#endif

