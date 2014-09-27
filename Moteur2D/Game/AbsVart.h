
#ifndef HEADER_VART_ABSTRAIT
#define HEADER_VART_ABSTRAIT

#include "Updatable.h"
#include "Deletable.h"
#include "../Graphic/ObjectDrawer.h"
#include "../Graphic/Sprite.h"
#include "../Graphic/Shape.h"


/*
Interface d'objet affichable ET pouvant etre mis a jour.
*/
class AbsVart : public Updatable, public Deletable
{
    public :

    virtual void drawIn(AbstractDrawer&) = 0;
};


#endif
