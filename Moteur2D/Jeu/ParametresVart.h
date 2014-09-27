
#ifndef HEADER_PARAMETRES_VART
#define HEADER_PARAMETRES_VART


#include "Vart.h"


namespace CtB
{

    class Vart::Parametres
    {
        public :

        Parametres(ObjetAffichable* nsprite, ObjetPhysique* nhitbox);

        ObjetAffichable* sprite();
        ObjetPhysique* hitbox();

        private :

        ObjetAffichable* m_sprite;
        ObjetPhysique* m_hitbox;
    };


}

#endif

