

#ifndef TEXTURE_LIST_HEADER
#define TEXTURE_LIST_HEADER

#include "..\Moteur2D\ResourceList.h"
#include <SFML/Graphics.hpp>

class TextureList : public ResourceList<sf::Texture>
{
    public :

    void loadTextures(const std::map<std::string, std::string>& textureAdresses, bool reloadIfPresent = false);
};



#endif // TEXTURE_LIST_HEADER

