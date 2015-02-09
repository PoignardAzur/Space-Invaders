


#ifndef HURTABLE_ENTITY_HEADER
#define HURTABLE_ENTITY_HEADER


class HurtableEntity
{
    public :

    virtual int takeDamage(int dm) = 0;     // returns the damages actually taken, which are inferior to dm if the entity dies
};



#endif
