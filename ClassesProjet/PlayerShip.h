


#ifndef PLAYER_SHIP_HEADER
#define PLAYER_SHIP_HEADER

#include "MainDimensions.h"

#define SHOOT_BUTTON sf::Keyboard::Space
#define COOLDOWN_TIME 0.3f
#define HITBOX_PLAYER_SHIP sf::IntRect(0,20, 60,40)
#define POSITION_PLAYER_SHIP sf::Vector2f( (LARGEUR_FENETRE / 2) - 10, HAUTEUR_FENETRE - (HAUTEUR_HUD + 50) )


//#include "Moteur2D.h"
#include "Weaponry/Weapon.h"


class PlayerShip : public Vart, public HurtableEntity
{
    public :

    PlayerShip(Inputs* in = 0, Sprite* spriteIdle = 0, Sprite* spriteShoot = 0);
    PlayerShip(Sprite* spriteIdle, Sprite* spriteShoot = 0);
    void set(Inputs* in, Sprite* spriteIdle = 0, Sprite* spriteShoot = 0);
    void set(Sprite* spriteIdle, Sprite* spriteShoot = 0);
    void setBulletArray(VartArray<Bullet>* bulletArray);
    void setBullets(sf::Sprite bulletSprite);

    void update(float tick_size);

    int takeDamage(int dm); /// TO CHANGE
    int kill();

    protected :

    bool tryToShoot();
    void reload(float ammo);

    void gotoLeft(float x);
    void gotoRight(float x);


    private :

    Inputs* m_inputs;

    boost::shared_ptr<Sprite> m_spriteIdle;     // has-a (shared by itself)
    boost::shared_ptr<Sprite> m_spriteShoot;    // has-a (shared by itself)

    Weapon m_weapon;
    sf::Vector2f m_center;
};




#endif

