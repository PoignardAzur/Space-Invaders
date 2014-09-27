



#ifndef HEADER_ALEA
#define HEADER_ALEA

#include <ctime>
//#include <cstdlib>



class Alea
{
    public :

    Alea()
    {
        srand(time(nullptr)); // initialise la graine
    }
/*
    Alea(int graine)
    {
        srand(graine); // initialise la graine
    }
*/
    int operator()(int maximum)
    {
        return rand() % (maximum + 1); // on obtient un nombre dans l'intervalle [0;max]
    }

    int operator()(int minimum, int maximum)
    {
        return rand() % (maximum + 1 - minimum) + minimum; // on obtient un nombre dans l'intervalle [min;max]
    }
};



#endif

