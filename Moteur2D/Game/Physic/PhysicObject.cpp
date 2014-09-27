


#include "PhysicObject.h"


//BOOST_CLASS_EXPORT_GUID(PhysicObject, "Phys")




PhysicObject::PhysicObject(sf::IntRect parametres, sf::Vector2f position, sf::Vector2f vitesse, sf::Vector2f acceleration) :
m_boite(parametres), m_position(position), m_vitesse(vitesse), m_acceleration(acceleration)
{ }

PhysicObject::PhysicObject(const PhysicObject& autre) : m_boite(autre.m_boite), m_position(autre.m_position), m_vitesse(autre.m_vitesse)
{ }


void PhysicObject::set(sf::Vector2f position, sf::Vector2f vitesse, sf::Vector2f acceleration)
{
    move(position);
    changeSpeed(vitesse);
    changeAcceleration(acceleration);
}

void PhysicObject::set(sf::IntRect boite)
{
    m_boite = boite;
}

void PhysicObject::set(const PhysicObject& autre)
{
    set(autre.relativeBox());
    set(autre.position(), autre.speed(), autre.acceleration());
}

sf::Vector2f PhysicObject::gap() const
{
    return sf::Vector2f(m_boite.left, m_boite.top);
}


sf::IntRect PhysicObject::absoluteBox() const
{
    return m_boite;
}

sf::IntRect PhysicObject::relativeBox() const
{
    return sf::IntRect(m_boite.left + position().x, m_boite.top + position().y, m_boite.height, m_boite.width);
}

void PhysicObject::changeAcceleration(sf::Vector2f n_acceleration, bool relatif)
{
    if (relatif)
    m_acceleration.value += n_acceleration;

    else
    m_acceleration.value = n_acceleration;
}

void PhysicObject::changeSpeed(sf::Vector2f nvitesse, bool relatif)
{
    if (relatif)
    m_vitesse.value += nvitesse;

    else
    m_vitesse = nvitesse;
}

void PhysicObject::move(sf::Vector2f nposition, bool relatif)
{
    if (relatif)
    m_position += nposition;

    else
    m_position = nposition;
}

sf::Vector2f PhysicObject::position() const
{
    return m_position;
}

sf::Vector2f PhysicObject::speed() const
{
    return m_vitesse.value;
}

sf::Vector2f PhysicObject::acceleration() const
{
    return m_acceleration.value;
}


bool testCollision(const PhysicObject& objet1, const PhysicObject& objet2)
{
    return testCollision(objet1.absoluteBox(), objet2.absoluteBox());
}

void PhysicObject::update(float tickSize)
{
    m_vitesse.deriver(m_position, tickSize);
    m_acceleration.deriver(m_vitesse.value, tickSize);
}



