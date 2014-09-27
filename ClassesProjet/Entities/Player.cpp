


#include "Player.hpp"



PlayerShip::PlayerShip(Sprite* spr, sf::IntRect hitbox, Inputs* in, BulletEmitter* weapon, Ship::Para para1, const Straffer::Para& para2, float nAmmo, float nMaxAmmo)
{
    set(spr, hitbox, in, weapon, para1, para2, nAmmo, nMaxAmmo);
}

void PlayerShip::set(Sprite* spr, sf::IntRect hitbox, Inputs* in, BulletEmitter* weapon, Ship::Para para1, const Straffer::Para& para2, float nAmmo, float nMaxAmmo)
{
    Ship::define(spr, hitbox, para1);
    Straffer::set(&m_controls);
    Straffer::set(para2);
    Shooter::set(nAmmo, nMaxAmmo);
    m_controls.setInputs(in);

    m_weapon = boost::shared_ptr<BulletEmitter>(weapon);
}

void PlayerShip::update(float ticks)
{
    Shooter::reload(ticks);

    if (m_controls.doShoot(*this, sf::Vector2f(0,0)));
//    Shooter::trytoShoot();

    Ship::update(ticks);
    Straffer::update(ticks);
}


void PlayerShip::moveLR(float distance)
{
    move(sf::Vector2f(distance, 0), true);
}

float PlayerShip::leftPos()
{
    return absoluteBox().left;
}

float PlayerShip::rightPos()
{
    return absoluteBox().left + absoluteBox().height;
}


