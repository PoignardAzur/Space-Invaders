


#include "SpriteCreator.h"



SpriteCreator::SpriteCreator(sf::Texture* texture)
{
    m_texture = texture;
}


Sprite* SpriteCreator::createConst(const int&) const
{
    sf::Sprite* spriteUtilise = new sf::Sprite(*m_texture);
    return new Sprite::Sprite(spriteUtilise, spriteUtilise);
}

Sprite* SpriteCreator::create(int& par) const
{
    return createConst(par);
}


