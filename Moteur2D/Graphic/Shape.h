

#ifndef HEADER_FORME_AFFICHABLE
#define HEADER_FORME_AFFICHABLE

#include "Drawable.h"

/*
Dessine une sf::shape dans la fenetre.
*/
class DrawableShape : public DrawableObject
{
    public :

    DrawableShape(sf::Shape* forme);

    sf::Shape& sprite();
    const sf::Shape& sprite() const; // A modifier, cette fonction est en fait un getter

    void setPosition(const sf::Vector2f& npos); // Pas un deplacement, mais une teleportation

    private :
    boost::shared_ptr<sf::Shape> m_sprite; // has-a

};





#endif


