
#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "AbsVart.h"
#include "../Graphic/Sprite.h"
#include "Physic/PhysicObject.h"


/*
Objet representant un objet de jeu avec un sprite, un comportement et une hitbox.
*/
class Vart : public AbsVart, public PhysicObject
{
    public :

    Vart(Sprite* sprite = 0, sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL);

    virtual void update(float tickSize);
    virtual bool doDelete() const;
    virtual void drawIn(AbstractDrawer&); // Classique

    protected :

    void setSprite(Sprite* para); // Setters
    void setSprite(boost::shared_ptr<Sprite> para);
    void setHitbox(const PhysicObject&);

    virtual void removeThis();


    private :

    boost::shared_ptr<Sprite> m_sprite; // has a
    bool m_detruit;
};



#endif
