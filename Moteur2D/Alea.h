



#ifndef HEADER_ALEA
#define HEADER_ALEA

#include <ctime>
//#include <cstdlib>


namespace CtB
{

    class Alea
    {
        public :

        Alea()
        {
            srand(time(0));
        }

        int operator()(int maximum)
        {
            return rand() % (maximum + 1); // on obtient un nombre dans l'intervalle [0;max]
        }

        int operator()(int minimum, int maximum)
        {
            return rand() % (maximum + 1 - minimum) + minimum; // on obtient un nombre dans l'intervalle [min;max]
        }
    };

}



#endif

