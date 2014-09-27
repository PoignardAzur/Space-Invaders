



#ifndef SPRITE_CREATOR_HEADER
#define SPRITE_CREATOR_HEADER

#include "Moteur2D.h"

class SpriteCreator : public Emitter<Sprite, int>
{
    public :

    SpriteCreator(sf::Texture* texture = 0);

    Sprite* createConst(const int&) const;
    Sprite* create(int& par) const;

    private :
    sf::Texture* m_texture;
};


#endif

