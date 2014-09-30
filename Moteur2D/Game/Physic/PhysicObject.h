


#ifndef HEADER_OBJET_PHYSIQUE
#define HEADER_OBJET_PHYSIQUE

#include "collisions.h"
#include "Derivee.h"
#include "../Updatable.h"

#define PT_NUL sf::Vector2f(0,0)
#define RECT_NUL sf::FloatRect(0,0,0,0)

#include "../../Graphic/AbstractDrawer.h"

// Sans doute à modifier
class PhysicObject : public Updatable
{
    public :

    explicit PhysicObject(sf::FloatRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL, sf::Vector2f acceleration = PT_NUL);
    PhysicObject(const PhysicObject&);
    virtual ~PhysicObject() {}

    void set(sf::Vector2f position, sf::Vector2f vitesse = PT_NUL, sf::Vector2f acceleration = PT_NUL);
    void setHitbox(sf::FloatRect nInternBox);
    void set(const PhysicObject&);

    sf::FloatRect internBox() const;
    sf::FloatRect placedBox() const;
    sf::Vector2f gap() const;

    void move(sf::Vector2f nposition, bool relatif = false);
    virtual void changeSpeed(sf::Vector2f nvitesse, bool relatif = false);
	virtual void changeAcceleration(sf::Vector2f nvitesse, bool relatif = false);

    sf::Vector2f position() const;
    sf::Vector2f speed() const;
    sf::Vector2f acceleration() const;

    void update(float dt);
    void drawIn(AbstractDrawer&);


    private :

    sf::FloatRect m_boite;

    sf::Vector2f m_position;                // position = placed center
    Derivee<sf::Vector2f> m_vitesse;
    Derivee<sf::Vector2f> m_acceleration;

    sf::Color m_color;
};



sf::Vector2f center(const sf::FloatRect& box);
bool testCollision(const PhysicObject& objet1, const PhysicObject& objet2);



#endif

