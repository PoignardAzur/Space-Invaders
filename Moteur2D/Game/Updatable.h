

#ifndef HEADER_MAJABLE
#define HEADER_MAJABLE


/*
Interface d'objet pouvant etre mis a jour.
*/
class Updatable
{
    public : virtual void update(float tickSize) = 0;
};




#endif

