

#ifndef RESSOURCE_LIST_HEADER
#define RESSOURCE_LIST_HEADER

#include <functional>
#include <map>
#include <vector>
#include <string>



template <typename R>
class RessourceList
{
    protected : typedef std::function<bool(R&, std::string*)> loadingFunction;
    // prototype must be bool loadingFunction(R& texture, std::string* error);

    public :

    RessourceList();

    const std::map<std::string, R>& list() const;
    const R& texture(const std::string& name) const;
    R& texture(const std::string& name);

    void load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadAll = false);  // the first string stands for the ressource's name
    void unload(const std::vector<std::string>& toUnload, bool keepLoaded = false);     // if keepLoaded = true, then only the names in toUnload are kept

    void unload();    // unloads everything


    private :

    std::map<std::string, R> m_ressources;


    public :

    template <typename T>
    void unload(const std::map<std::string, T>& toUnload, bool keepLoaded = false)
    {
        for (const auto& _name : toUnload)
        {
            const std::string& name = _name.first;

            if (m_ressources.find(name) == m_ressources.end())  // if name isn't in m_ressources
            {
                if (keepLoaded)
                m_ressources.erase(name);
            }

            else if (! keepLoaded)
            m_ressources.erase(name);
        }
    }
};

template <typename R>
RessourceList<R>::RessourceList()
{

}

template <typename R>
const std::map<std::string, R>& RessourceList<R>::list() const
{
    return m_ressources;
}

template <typename R>
const R& RessourceList<R>::texture(const std::string& name) const
{
    return m_ressources.at(name);
}

template <typename R>
R& RessourceList<R>::texture(const std::string& name)
{
    return m_ressources[name];
}

// the first string stands for the ressource's name
template <typename R>
void RessourceList<R>::load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadAll)
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
template <typename R>
void RessourceList<R>::unload(const std::vector<std::string>& toUnload, bool keepLoaded)
{
    for (const std::string& name : toUnload)
    {
        if (m_ressources.find(name) == m_ressources.end())  // if name isn't in m_ressources
        {
            if (keepLoaded)
            m_ressources.erase(name);
        }

        else if (! keepLoaded)
        m_ressources.erase(name);
    }
}

template <typename R>
void RessourceList<R>::unload()
{
    m_ressources.clear();
}





#endif // TEXTURE_LIST_HEADER


