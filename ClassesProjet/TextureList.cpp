

#include "TextureList.h"




std::map<std::string, sf::Texture>& TextureList::list()
{
    return m_textureList;
}

const std::map<std::string, sf::Texture>& TextureList::list() const
{
    return m_textureList;
}


const sf::Texture* TextureList::texture(const std::string& name) const
{
    if (m_baseTextureList.find(name) != m_baseTextureList.end())    // if m_baseTextureList[name] exists
    return & m_baseTextureList.at(name);

/// else
    return & m_textureList.at(name);         // the .at() is important because this is a constant method
}




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



void TextureList::loadTextures(const std::map<std::string, loadingFunction>& textures)
{
    std::map<std::string, bool> isAlreadyLoaded;

    for (auto& p : textures)
    {
        isAlreadyLoaded[p.first] = false;
    }

    for (auto& p : list())
    {
        if (textures.find(p.first) != textures.end())
        {
            isAlreadyLoaded[p.first] = true;
        }

        else
        {
            m_textureList.erase(p.first);
        }
    }

    std::string errorMessage;

    for (auto& p : textures)
    {
        if (! isAlreadyLoaded[p.first])
        {
            if (! p.second(m_textureList[p.first], &errorMessage))
            {
                if (errorMessage == "")
                throw "Error : cannot load texture " + p.first + ".";

                else
                throw "Error : cannot load texture " + p.first + " ;" "\n" "Reason given : " + errorMessage;
            }
        }
    }
}


void TextureList::loadBaseTextures(const std::map<std::string, loadingFunction>& textures)
{
    std::string errorMessage;

    for (auto& p : textures)
    {
        if (! p.second(m_baseTextureList[p.first], &errorMessage))
        {
            if (errorMessage == "")
            throw "Error : cannot load texture " + p.first + ".";

            else
            throw "Error : cannot load texture " + p.first + " ;" "\n" "Reason given : " + errorMessage;
        }
    }
}



void TextureList::loadTextures(const std::map<std::string, std::string>& textureAdresses)
{
    std::map<std::string, loadingFunction> textures;

    for (auto& p : textureAdresses)
    {
        textures[p.first] = loadTextureFrom(p.second);
    }

    loadTextures(textures);
}


void TextureList::loadBaseTextures(const std::map<std::string, std::string>& textureAdresses)
{
    std::map<std::string, loadingFunction> textures;

    for (auto& p : textureAdresses)
    {
        textures[p.first] = loadTextureFrom(p.second);
    }

    loadBaseTextures(textures);
}











