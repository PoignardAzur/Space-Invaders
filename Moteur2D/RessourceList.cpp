

#include "RessourceList.h"


RessourceList::RessourceList()
{

}

const std::map<std::string, R>& RessourceList::list() const
{
    return m_ressources;
}

const R& RessourceList::texture(const std::string& name) const
{
    return m_ressources.at(name);
}

R& RessourceList::texture(const std::string& name)
{
    return m_ressources[name];
}

// the first string stands for the ressource's name
void RessourceList::load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadAll)
{
    std::string error;

    if (reloadAll)
    unload();

    for (const auto& ressourceLoader : ressourceLoaders)
    {
        if (list().find(ressourceLoader.first) == list().end())
        {
            if (! ressourceLoader.second(m_ressources[ressourceLoader.first], &error))
            throw "Error while loading " + ressourceLoader.first + " :" "\n" + error;
        }
    }
}

// if keepLoaded = true, then only the names in toUnload are kept
void RessourceList::unload(const std::vector<std::string>& toUnload, bool keepLoaded)
{
    for (const auto& ressource : m_ressources)
    {
        if (toUnload.find(ressource.first) != toUnload.end() ^^ keepLoaded)
        {
            m_ressources.erase(ressource.first);
        }
    }
}

void RessourceList::unload()
{
    m_ressources.clear();
}













