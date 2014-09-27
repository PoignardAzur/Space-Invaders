

#ifndef HEADER_DESTRUCTIBLE
#define HEADER_DESTRUCTIBLE



/*
Interface d'objet pouvant etre detruit.
*/
class Deletable
{
    public : virtual bool doDelete() const = 0;
};




#endif



