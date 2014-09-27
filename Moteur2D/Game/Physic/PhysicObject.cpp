


#include "PhysicObject.h"




PhysicObject::PhysicObject(sf::IntRect nBoite, sf::Vector2f position, sf::Vector2f vitesse, sf::Vector2f acceleration) :
m_boite(nBoite), m_position(position), m_vitesse(vitesse), m_acceleration(acceleration)
{ }

PhysicObject::PhysicObject(const PhysicObject& other) : m_boite(other.m_boite), m_position(other.m_position), m_vitesse(other.m_vitesse)
{ }


void PhysicObject::set(sf::Vector2f position, sf::Vector2f vitesse, sf::Vector2f acceleration)
{
    move(position);
    changeSpeed(vitesse);
    changeAcceleration(acceleration);
}

void PhysicObject::setHitbox(sf::IntRect boite)
{
    m_boite = boite;
}

void PhysicObject::set(const PhysicObject& other)
{
    setHitbox(other.internBox());
    set(other.position(), other.speed(), other.acceleration());
}

sf::Vector2f PhysicObject::gap() const
{
    return sf::Vector2f(m_boite.left, m_boite.top);
}



sf::IntRect PhysicObject::internBox() const
{
    return m_boite;
}

sf::IntRect PhysicObject::placedBox() const
{
    return sf::IntRect(m_boite.left + position().x, m_boite.top + position().y, m_boite.width, m_boite.height);
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
    m_vitesse.value = nvitesse;
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


void PhysicObject::update(float tickSize)
{
    m_vitesse.deriver(m_position, tickSize);
    m_acceleration.deriver(m_vitesse.value, tickSize);
}


sf::Vector2f center(const sf::IntRect& rect)
{
    return sf::Vector2f(rect.left + (rect.width / 2), rect.top + (rect.height / 2));
}

bool testCollision(const PhysicObject& objet1, const PhysicObject& objet2)
{
    if( testCollision(objet1.placedBox(), objet2.placedBox()) )
    {
        return true;
    }
    else return false;
}


