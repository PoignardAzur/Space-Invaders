


#ifndef PLAYER_SHIP_HEADER
#define PLAYER_SHIP_HEADER

#include "MainDimensions.h"

#define SHOOT_BUTTON sf::Keyboard::Space
#define COOLDOWN_TIME 0.3f
#define HITBOX_PLAYER_SHIP sf::IntRect(0,20, 60,40)
#define POSITION_PLAYER_SHIP sf::Vector2f( (LARGEUR_FENETRE / 2) - 10, HAUTEUR_FENETRE - 50 )


//#include "Moteur2D.h"
#include "Weaponry/Weapon.h"


class PlayerShip : public BaseVart, public HurtableEntity
{
    public :

    PlayerShip();
    PlayerShip(const sf::Sprite& spriteIdle, const sf::Sprite& spriteShoot, AbstractInputs* in = nullptr);
    virtual ~PlayerShip();

    void set(AbstractInputs* in, const sf::Sprite& spriteIdle, const sf::Sprite& spriteShoot, float leftLimit, float rightLimit);
    void setSprites(const sf::Sprite& spriteIdle, const sf::Sprite spriteShoot);
    void setLimits(float left, float right);
    void setInputs(AbstractInputs* in);

    void addWeapon(Weapon* w);
    int takeDamage(int dm);                 /// TO CHANGE
    int kill();

    void update(float tick_size);


    protected :

    bool tryToShoot();
    void reload(float ammo);

    void gotoLeft(float x);
    void gotoRight(float x);

    Weapon* selectedWeapon();
    const Weapon* selectedWeapon() const;


    private :

    AbstractInputs* m_inputs;

    sf::Sprite m_spriteIdle;                // The ship keeps this sprite until it shoots
    sf::Sprite m_spriteShoot;               // The ship gets this sprite after shooting and keeps it a few ticks

    std::vector<Weapon*> m_weapons;
    unsigned short m_selectedWeaponSlot;

    sf::Vector2f m_center;

    float m_leftLimit;                      // The ship cannot go further left than m_leftLimit or further right than m_rightLimit
    float m_rightLimit;
};




#endif

