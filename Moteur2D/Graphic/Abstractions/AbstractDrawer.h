


#ifndef HEADER_AFFICHEUR_OBJETS_ABSTRAIT
#define HEADER_AFFICHEUR_OBJETS_ABSTRAIT

#include <SFML/Graphics.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>


class AbstractDrawable;


class AbstractDrawer
{
    public :
    virtual void clear();

    protected :
    virtual sf::RenderTarget& target() = 0;

    public :

    virtual void draw(const AbstractDrawable& objet);
};





#endif


