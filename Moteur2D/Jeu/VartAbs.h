
#ifndef HEADER_VART_ABSTRAIT
#define HEADER_VART_ABSTRAIT

#include "Majable.h"
#include "../Graphique/AfficheurObjets.h"
#include "../Graphique/Sprite.h"
#include "../Graphique/Forme.h"


namespace CtB
{

    class VartAbs : public Majable
    {
        public :

        virtual void afficherDans(AfficheurObjets&) = 0;
    };

}


#endif
