

#include "AbstractDrawer.h"
#include "AbstractDrawable.h"


void AbstractDrawer::clear()
{
    target().clear();
}


void AbstractDrawer::draw(const AbstractDrawable& objet)
{
    objet.drawIn(target());
}

