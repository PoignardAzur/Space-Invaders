
#ifndef HEADER_VART_ABSTRAIT
#define HEADER_VART_ABSTRAIT

#include "Majable.h"
#include "../Graphique/AfficheurObjets.h"


namespace CtB
{

    class VartAbs : public Majable
    {
        public :

        virtual void afficherDans(const AfficheurObjets&) = 0;
    };

}


#endif
