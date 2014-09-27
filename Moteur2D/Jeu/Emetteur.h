

#ifndef HEADER_EMMETTEUR
#define HEADER_EMMETTEUR

#include "Vart.h"
#include "TableauVarts.h"
#include <SFML/Graphics.hpp>



template <typename T>
class Emetteur
{
    public :

    virtual void attribuer(TableauVart<T>& ncible);
    virtual void tirer(sf::Vector2f position) = 0;

    protected :
    TableauVart<T>& cible();

    private :
    TableauVart<T>* m_cible;
};


template <typename T>
TableauVart<T>& Emetteur<T>::cible()
{
    return *m_cible;
}

template <typename T>
void Emetteur<T>::attribuer(TableauVart<T>& ncible)
{
    m_cible = &ncible;
}





#endif

