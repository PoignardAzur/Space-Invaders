


#ifndef BULLET_EMITTER_HEADER
#define BULLET_EMITTER_HEADER

#include "../Moteur2D/Game/Emitter.h"
#include "Entities/Bullet.h"

class BulletEmitter : public Emitter<Bullet, sf::Vector2f>
{
    public :

    BulletEmitter(Emitter<Sprite, int>* spriteCreator, sf::IntRect m_hitbox, float m_vitesse);

    Bullet* createConst(const sf::Vector2f&) const;
    Bullet* create(sf::Vector2f& par) const;

    private :

    boost::shared_ptr< Emitter<Sprite, int> > m_spriteCreator;
    int m_nCalls;

    sf::IntRect m_hitbox;
    sf::Vector2f m_vitesse;

};



#endif
