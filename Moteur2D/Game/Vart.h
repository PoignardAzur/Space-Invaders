

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "AbsVart.h"
#include "../Graphic/Sprite.h"
#include "Physic/PhysicObject.h"


/*
Objet representant un objet de jeu avec un sprite, un comportement et une hitbox.
*/
class Vart : public AbsVart, public PhysicObject //protected PhysicObject
{
    public :

    Vart(Sprite* sprite = 0, sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL);

    virtual void update(float tickSize);
    virtual bool doDelete() const;
    virtual void drawIn(AbstractDrawer&); // Classique

    /// Comportement : TODO ?

    protected :

    void setSprite(Sprite* para); // Setters
    void setHitbox(const PhysicObject&);

    virtual void removeThis();


    private :

    boost::shared_ptr<Sprite> m_sprite; // has a
    bool m_detruit;

/*
    friend class boost::serialization::access;

    template <typename Flux>
    void serialize(Flux& f, const unsigned long int version);
};


template <typename Flux>
void Vart::serialize(Flux& f, const unsigned long int version)
{
    f & boost::serialization::base_object<ObjetPhysique>(*this);
}



BOOST_CLASS_EXPORT_GUID(Vart, "Vart")
//*/};



#endif
