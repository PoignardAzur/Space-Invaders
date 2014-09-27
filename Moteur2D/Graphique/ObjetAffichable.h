

#ifndef HEADER_OBJET_AFFICHABLE
#define HEADER_OBJET_AFFICHABLE

#include <SFML/Graphics.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>



class ObjetAffichable
{
    public :

    virtual const sf::Drawable& afficher() const = 0;
    virtual void MAJ() {}
};






#endif

