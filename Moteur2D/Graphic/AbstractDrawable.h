

#ifndef HEADER_OBJET_AFFICHABLE_ABSTRAIT
#define HEADER_OBJET_AFFICHABLE_ABSTRAIT

/*
Interface for drawable objects
*/
class AbstractDrawer;

class AbstractDrawable
{
    public :

    virtual ~AbstractDrawable() {}
    virtual void drawIn(AbstractDrawer& cible) const = 0;
};


#include "AbstractDrawer.h"




#endif


