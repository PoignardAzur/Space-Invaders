

#ifndef RESSOURCE_LIST_HEADER
#define RESSOURCE_LIST_HEADER

#include <functional>
#include <map>
#include <vector>
#include <string>



template <typename R>
class ResourceList
{
    protected : typedef std::function<bool(R&, std::string*)> loadingFunction;
    // prototype must be bool loadingFunction(R& texture, std::string* error);

    public :

    ResourceList();

    const std::map<std::string, R>& list() const;
    const R& operator[](const std::string& name) const;
    R& operator[](const std::string& name);

    void load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadIfPresent = false);  // the first string stands for the ressource's name
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
ResourceList<R>::ResourceList()
{

}

template <typename R>
const std::map<std::string, R>& ResourceList<R>::list() const
{
    return m_ressources;
}

template <typename R>
const R& ResourceList<R>::operator[](const std::string& name) const
{
    return m_ressources.at(name);
}

template <typename R>
R& ResourceList<R>::operator[](const std::string& name)
{
    return m_ressources[name];
}

// the first string stands for the ressource's name
template <typename R>
void ResourceList<R>::load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadIfPresent)
{
    std::string error;

    for (const auto& ressourceLoader : ressourceLoaders)
    {
        if (list().find(ressourceLoader.first) == list().end() || reloadIfPresent)
        {
            if (! ressourceLoader.second(m_ressources[ressourceLoader.first], &error))
            throw "Error while loading " + ressourceLoader.first + " :" "\n" + error;
        }
    }
}


// if keepLoaded = true, then only the names in toUnload are kept
template <typename R>
void ResourceList<R>::unload(const std::vector<std::string>& toUnload, bool keepLoaded)
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
void ResourceList<R>::unload()
{
    m_ressources.clear();
}





#endif // TEXTURE_LIST_HEADER


