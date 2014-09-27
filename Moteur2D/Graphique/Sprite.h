

#ifndef HEADER_SPRITE
#define HEADER_SPRITE

#include "ObjetAffichable.h"




class Sprite : public ObjetAffichable
{
    public :

    Sprite();
    Sprite(const sf::Texture& paraObjet);

    void attribuer(const sf::Texture& paraObjet);

    sf::Sprite& afficher();
    const sf::Sprite& afficher() const;

    void deplacer(const sf::Vector2f& distance);

    protected :

    private :

    sf::Sprite m_sprite;

};









#endif

