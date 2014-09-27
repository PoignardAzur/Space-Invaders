

#include "TextureList.h"


bool loadTextureFromFile(sf::Texture& texture, const std::string& file, std::string* errorMessage)
{
    sf::Image image;
    image.loadFromFile(file);
    image.createMaskFromColor(sf::Color::White);

    return texture.loadFromImage(image);
}

std::function<bool(sf::Texture&, std::string*)> loadTextureFrom(const std::string& file)
{
    using namespace std::placeholders;
    return std::bind(loadTextureFromFile, _1, file, _2);
}



void TextureList::loadTextures(const std::map<std::string, std::string>& textureAdresses, bool reloadAll)
{
    std::map<std::string, loadingFunction> textures;

    for (const auto& p : textureAdresses)
    {
        textures[p.first] = loadTextureFrom(p.second);
    }

    RessourceList<sf::Texture>::load(textures, reloadAll);
}



