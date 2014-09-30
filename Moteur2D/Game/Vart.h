
#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "AbsVart.h"
#include "Physic/PhysicObject.h"

#define DRAW_VART_SPRITE true
#define DRAW_VART_HITBOX true

/*
Represents a basic object with a provided hitbox and appearance.
*/

template <typename Phys, typename Spr>
class Vart : public AbsVart, public Phys
{
    public :

    Vart();
    explicit Vart(const Phys& hitbox);
    explicit Vart(const Spr& sprite, sf::Vector2f relativePosition = sf::Vector2f(0,0));
    Vart(const Spr& sprite, const Phys& hitbox);
    virtual ~Vart();

    virtual void update(float dt);
    virtual bool doDelete() const;
    void drawIn(AbstractDrawer&); // inherited virtual methods ; has to be defined here
    virtual void drawIn(AbstractDrawer&, bool drawSprite, bool drawHitbox = DRAW_VART_HITBOX);


    protected :

    void setSprite(const Spr& sprite);
    void setSprite(const Spr& sprite, sf::Vector2f relativePosition);
    void setSpriteRelativePosition(sf::Vector2f pos);
    virtual void removeThis();


    private :

    Spr m_sprite;
    bool m_toDelete = false;
    sf::Vector2f m_spriteRelativePosition;
};


using BaseVart = Vart<PhysicObject, sf::Sprite>;


template <typename Phys, typename Spr>
Vart<Phys, Spr>::Vart()
{

}

template <typename Phys, typename Spr>
Vart<Phys, Spr>::Vart(const Phys& hitbox) : Phys(hitbox)
{

}

template <typename Phys, typename Spr>
Vart<Phys, Spr>::Vart(const Spr& sprite, sf::Vector2f relativePosition) :
m_sprite(sprite), m_spriteRelativePosition(relativePosition)
{

}

template <typename Phys, typename Spr>
Vart<Phys, Spr>::Vart(const Spr& sprite, const Phys& hitbox) : Phys(hitbox), m_sprite(sprite)
{

}

template <typename Phys, typename Spr>
Vart<Phys, Spr>::~Vart()
{

}


template <typename Phys, typename Spr>
void Vart<Phys, Spr>::update(float dt)
{
    Phys::update(dt);
}


template <typename Phys, typename Spr>
bool Vart<Phys, Spr>::doDelete() const
{
    return m_toDelete;
}


template <typename Phys, typename Spr>
void Vart<Phys, Spr>::drawIn(AbstractDrawer& cible, bool drawSprite, bool drawHitbox)
{
    if (drawSprite)
    {
        m_sprite.setPosition(Phys::position() + m_spriteRelativePosition);
        cible.draw(m_sprite);
    }

    if (drawHitbox)
    {
        Phys::drawIn(cible);
    }
}

template <typename Phys, typename Spr>
void Vart<Phys, Spr>::drawIn(AbstractDrawer& cible)
{
    drawIn(cible, DRAW_VART_SPRITE, DRAW_VART_HITBOX);
}



template <typename Phys, typename Spr>
void Vart<Phys, Spr>::removeThis()
{
    m_toDelete = true;
}


template <typename Phys, typename Spr>
void Vart<Phys, Spr>::setSprite(const Spr& para)
{
    m_sprite = para;
}


template <typename Phys, typename Spr>
void Vart<Phys, Spr>::setSprite(const Spr& para, sf::Vector2f relativePosition)
{
    setSprite(para);
    setSpriteRelativePosition(relativePosition);
}


template <typename Phys, typename Spr>
void Vart<Phys, Spr>::setSpriteRelativePosition(sf::Vector2f pos)
{
    m_spriteRelativePosition = pos;
}






#endif
