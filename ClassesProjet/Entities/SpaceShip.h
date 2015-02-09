

#ifndef SPACESHIP_HEADER
#define SPACESHIP_HEADER

#include "../../Moteur2D/Game/SimpleVart.h"


class SpaceShip : public SimpleVart
{
    public :

    virtual int takeDamage(int dm) = 0;     // returns the damages actually taken, which are inferior to dm if the entity dies
    virtual float highLimit() = 0;          // returns how high its y coordinate has to be oob, thus not drawn (above the screen)
    virtual float lowLimit() = 0;           // returns how low its y coordinate has to be oob, thus not drawn (under the screen)

    protected :


    private :


};


#endif // SPACESHIP_HEADER
