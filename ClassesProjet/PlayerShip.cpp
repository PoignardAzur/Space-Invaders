

#include "PlayerShip.h"




PlayerShip::PlayerShip()
{

}



PlayerShip::PlayerShip(const sf::Sprite& spriteIdle, const sf::Sprite& spriteShoot, AbstractInputs* in)
{
    setInputs(in);
    setSprites(spriteIdle, spriteShoot);

    BaseVart::set(POSITION_PLAYER_SHIP);
    BaseVart::PhysicObject::setHitbox(HITBOX_PLAYER_SHIP);
}



void PlayerShip::set(AbstractInputs* in, const sf::Sprite& spriteIdle, const sf::Sprite& spriteShoot, float leftLimit, float rightLimit)
{
    setInputs(in);
    setSprites(spriteIdle, spriteShoot);
    setLimits(leftLimit, rightLimit);
}

 PlayerShip::~PlayerShip()
{
    for (Weapon* w : m_weapons)
    {
        delete w;
    }
}



void PlayerShip::setInputs(AbstractInputs* in)
{
    m_inputs = in;
}

void PlayerShip::setSprites(const sf::Sprite& spriteIdle, const sf::Sprite spriteShoot)
{
    m_spriteIdle = spriteIdle;
    m_spriteShoot = spriteShoot;

    BaseVart::setSprite(m_spriteIdle);

    m_center = center(HITBOX_PLAYER_SHIP);
}


void PlayerShip::setLimits(float left, float right)
{
    m_leftLimit = left;
    m_rightLimit = right;
}


void PlayerShip::addWeapon(Weapon* w)
{
    m_weapons.push_back(w);
    m_selectedWeaponSlot = m_weapons.size() - 1;
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
    BaseVart::update(tick_size);

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
    if (selectedWeapon() && selectedWeapon()->tryToShoot(position() + m_center))
    {
        Vart::setSprite(m_spriteShoot);
        return true;
    }

    return false;
}


void PlayerShip::reload(float ammo)
{
    if (selectedWeapon())
    {
        if (selectedWeapon()->update(ammo))
        Vart::setSprite(m_spriteIdle);

        if (selectedWeapon()->ammo() == 0)
        {
            delete selectedWeapon();
            m_weapons.erase(m_weapons.begin() + m_selectedWeaponSlot);
            m_selectedWeaponSlot --;

            if (m_selectedWeaponSlot < 0)
            m_selectedWeaponSlot = m_weapons.size() - 1;
        }
    }
}



void PlayerShip::gotoLeft(float x)
{
    BaseVart::move(sf::Vector2f(-x,0), true);

    if (BaseVart::position().x < m_leftLimit)
    BaseVart::move(sf::Vector2f(m_leftLimit, BaseVart::position().y), false);
}


void PlayerShip::gotoRight(float x)
{
    BaseVart::move(sf::Vector2f(x,0), true);

    if (BaseVart::position().x + internBox().width > m_rightLimit)
    BaseVart::move(sf::Vector2f(m_rightLimit - internBox().width, BaseVart::position().y), false);
}




Weapon* PlayerShip::selectedWeapon()
{
    if (m_selectedWeaponSlot >= 0 && m_selectedWeaponSlot < m_weapons.size())
    return m_weapons[m_selectedWeaponSlot];

    else
    return nullptr;
}

const Weapon* PlayerShip::selectedWeapon() const
{
    return const_cast<PlayerShip*>(this)->selectedWeapon();
}










