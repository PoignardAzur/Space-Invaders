


#ifndef HEADER_OBJET_PHYSIQUE
#define HEADER_OBJET_PHYSIQUE


//#include <boost/serialization/base_object.hpp>

#include "collisions.h"
#include "Derivee.h"
#include "../Updatable.h"

#define PT_NUL sf::Vector2f(0,0)
#define RECT_NUL sf::IntRect(0,0,0,0)



// Sans doute à modifier
class PhysicObject : public Updatable
{
    public :

    PhysicObject(sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL, sf::Vector2f acceleration = PT_NUL);
    PhysicObject(const PhysicObject&);

    void set(sf::Vector2f position, sf::Vector2f vitesse = PT_NUL, sf::Vector2f acceleration = PT_NUL);
    void set(sf::IntRect parametres);
    void set(const PhysicObject&);

    sf::IntRect absoluteBox() const;
    sf::IntRect relativeBox() const;
    sf::Vector2f gap() const;

    void move(sf::Vector2f nposition, bool relatif = false);
    virtual void changeSpeed(sf::Vector2f nvitesse, bool relatif = false);
	virtual void changeAcceleration(sf::Vector2f nvitesse, bool relatif = false);

    sf::Vector2f position() const;
    sf::Vector2f speed() const;
    sf::Vector2f acceleration() const;

    void update(float tickSize);

    private :

    sf::IntRect m_boite;

    sf::Vector2f m_position;
    Derivee<sf::Vector2f> m_vitesse;
    Derivee<sf::Vector2f> m_acceleration;

  //  friend class boost::serialization::access;

  //  template <typename Flux>
//    void serialize(Flux& f, const unsigned int version);
};

/*namespace boost { namespace serialization { template <typename Flux>
void serialize(Flux& f, sf::IntRect& rect, const unsigned int version)
{
    f & rect.left;
    f & rect.top;
    f & rect.width;
    f & rect.height;
}}}

template <typename Flux>
void PhysicObject::serialize(Flux& f, const unsigned int version)
{
    f & boost::serialization::base_object<Mouvement>(*this);
    f & m_boite;
}
*/




bool testCollision(const PhysicObject& objet1, const PhysicObject& objet2);



#endif

