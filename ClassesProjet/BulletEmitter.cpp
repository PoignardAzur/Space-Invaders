

#include "BulletEmitter.h"



BulletEmitter::BulletEmitter(Emitter<Sprite, int>* spriteCreator, sf::IntRect hitbox, float vitesse) :
m_spriteCreator(spriteCreator), m_nCalls(0), m_hitbox(hitbox), m_vitesse(0, vitesse)
{

}


Bullet* BulletEmitter::createConst(const sf::Vector2f& pos) const
{
    return new Vart(m_spriteCreator->createConst(m_nCalls), m_hitbox, pos, m_vitesse);
}


Bullet* BulletEmitter::create(sf::Vector2f& pos) const
{
    return createConst(pos);
}

