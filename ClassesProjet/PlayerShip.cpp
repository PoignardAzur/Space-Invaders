

#include "PlayerShip.h"


PlayerShip::PlayerShip(Inputs* in, Sprite* spriteIdle, Sprite* spriteShoot) : m_weapon(COOLDOWN_TIME, 0)
{
    m_inputs = in;
    set(spriteIdle, spriteShoot);
    Vart::set(POSITION_PLAYER_SHIP);
    Vart::set(HITBOX_PLAYER_SHIP);
}

PlayerShip::PlayerShip(Sprite* spriteIdle, Sprite* spriteShoot) : m_weapon(COOLDOWN_TIME, 0)
{
    set(spriteIdle, spriteShoot);
    Vart::set(POSITION_PLAYER_SHIP);
    Vart::set(HITBOX_PLAYER_SHIP);
}

void PlayerShip::set(Inputs* in, Sprite* spriteIdle, Sprite* spriteShoot)
{
    m_inputs = in;
    set(spriteIdle, spriteShoot);
}

void PlayerShip::set(Sprite* spriteIdle, Sprite* spriteShoot)
{
    if(spriteIdle)
    {
        m_spriteIdle = boost::shared_ptr<Sprite>(spriteIdle);
    }

    if (spriteShoot)
    {
        m_spriteShoot = boost::shared_ptr<Sprite>(spriteShoot);
        Vart::setSprite(m_spriteShoot);
    }

    m_center = center(HITBOX_PLAYER_SHIP);
}


void PlayerShip::setBulletArray(VartArray<Bullet>* bulletArray)
{
    m_weapon.set(bulletArray);
}

void PlayerShip::setBullets(sf::Sprite bulletSprite)
{
    m_weapon.set(bulletSprite);
}



int PlayerShip::takeDamage(int dm)
{
    return kill(); /// TO-CHANGE
}

int PlayerShip::kill()
{
    removeThis();
    return 0;  /// TO-CHANGE
}


void PlayerShip::update(float tick_size)
{
    Vart::update(tick_size);

    reload(tick_size);

    if (m_inputs->keyboardButtons()[SHOOT_BUTTON])
    tryToShoot();

    if (m_inputs->keyboardButtons()[sf::Keyboard::Left] && ! m_inputs->keyboardButtons()[sf::Keyboard::Down])
    gotoLeft(tick_size*200);

    if (m_inputs->keyboardButtons()[sf::Keyboard::Right] && ! m_inputs->keyboardButtons()[sf::Keyboard::Down])
    gotoRight(tick_size*200);

    if (m_inputs->keyboardButtons()[sf::Keyboard::Left] && m_inputs->keyboardButtons()[sf::Keyboard::Down])
    gotoLeft(tick_size*500);

    if (m_inputs->keyboardButtons()[sf::Keyboard::Right] && m_inputs->keyboardButtons()[sf::Keyboard::Down])
    gotoRight(tick_size*500);
}


bool PlayerShip::tryToShoot()
{
    if (m_weapon.tryToShoot(position() + m_center))
    {
        Vart::setSprite(m_spriteShoot);
        return true;
    }

    return false;
}


void PlayerShip::reload(float ammo)
{
    if (m_weapon.update(ammo))
    Vart::setSprite(m_spriteIdle);
}


void PlayerShip::gotoLeft(float x)
{
    Vart::move(sf::Vector2f(-x,0), true);
}


void PlayerShip::gotoRight(float x)
{
    Vart::move(sf::Vector2f(x,0), true);
}



