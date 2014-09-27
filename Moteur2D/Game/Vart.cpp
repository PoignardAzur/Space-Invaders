

#include "Vart.h"





Vart::Vart(Sprite* sprite, sf::IntRect para, sf::Vector2f pos, sf::Vector2f vit) :
PhysicObject(para, pos, vit), m_sprite(sprite), m_detruit(false)
{

}


void Vart::update(float tickSize)
{
    m_sprite->update(tickSize);
    PhysicObject::update(tickSize);
}


bool Vart::doDelete() const
{
    return m_detruit;
}


void Vart::drawIn(AbstractDrawer& cible)
{
    m_sprite->setPosition(position() - gap());
    cible.draw(*m_sprite);
}



void Vart::removeThis()
{
    m_detruit = true;
}



void Vart::setSprite(Sprite* para)
{
    m_sprite = boost::shared_ptr<Sprite>(para);
}


void Vart::setHitbox(const PhysicObject& para)
{
    PhysicObject::set(para);
}



