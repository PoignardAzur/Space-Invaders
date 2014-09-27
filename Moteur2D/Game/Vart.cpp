

#include "Vart.h"
#include <iostream>




Vart::Vart(Sprite* sprite, sf::IntRect para, sf::Vector2f pos, sf::Vector2f vit) : m_sprite(sprite), m_detruit(false)
{
    PhysicObject::set(para);
    PhysicObject::set(pos, vit);
}


void Vart::update(float tickSize)
{
    if (m_sprite)
    m_sprite->update(tickSize);
    PhysicObject::update(tickSize);
}


bool Vart::doDelete() const
{
    return m_detruit;
}

void Vart::drawIn(AbstractDrawer& cible)
{
    const_cast<Sprite*>(m_sprite.get())->setPosition(position());
    cible.draw(*m_sprite);
}



void Vart::removeThis()
{
    m_detruit = true;
}



void Vart::setSprite(Sprite* para)
{
    setSprite(boost::shared_ptr<Sprite>(para));
}

void Vart::setSprite(boost::shared_ptr<Sprite> para)
{
    m_sprite = para;
    const_cast<Sprite*>(m_sprite.get())->setPosition(position());
}

void Vart::setHitbox(const PhysicObject& para)
{
    PhysicObject::set(para);
}



