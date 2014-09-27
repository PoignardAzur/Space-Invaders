

#ifndef TEXTURE_LIST_HEADER
#define TEXTURE_LIST_HEADER

#include <functional>
#include <SFML/Graphics.hpp>

class TextureList
{
    typedef std::function<bool(sf::Texture&, std::string*)> loadingFunction;
    // prototype must be bool loadingFunction(sf::Texture& texture, const std::string&* filename);

    public :

    std::map<std::string, sf::Texture>& list();
    const std::map<std::string, sf::Texture>& list() const;

    const sf::Texture* texture(const std::string& name) const;
    void loadTextures(const std::map<std::string, loadingFunction>& textures);
    void loadBaseTextures(const std::map<std::string, loadingFunction>& textures);

    void loadTextures(const std::map<std::string, std::string>& textureAdresses);
    void loadBaseTextures(const std::map<std::string, std::string>& textureAdresses);


    private :

    std::map<std::string, sf::Texture> m_textureList;       // change every level
    std::map<std::string, sf::Texture> m_baseTextureList;   // stay the same for every level
};



#endif // TEXTURE_LIST_HEADER

