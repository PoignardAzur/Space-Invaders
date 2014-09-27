

#ifndef TEXTURE_LIST_HEADER
#define TEXTURE_LIST_HEADER

#include "..\Moteur2D\RessourceList.h"
#include <SFML/Graphics.hpp>

class TextureList : public RessourceList<sf::Texture>
{
    public :

    void loadTextures(const std::map<std::string, std::string>& textureAdresses, bool reloadAll = false);
};



#endif // TEXTURE_LIST_HEADER

