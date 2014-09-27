

#ifndef RESSOURCE_LIST_HEADER
#define RESSOURCE_LIST_HEADER

#include <functional>
#include <map>
#include <vector>
#include <string>


typedef double R;   // note : R must be easily copiable

class RessourceList
{
    typedef std::function<bool(R&, const std::string*)> loadingFunction;
    // prototype must be bool loadingFunction(R& texture, const std::string* error);

    public :

    RessourceList();

    const std::map<std::string, R>& list() const;
    const R& texture(const std::string& name) const;
    R& texture(const std::string& name);

    void load(const std::map<std::string, loadingFunction>& ressourceLoaders, bool reloadAll = true);  // the first string stands for the ressource's name
    void unload(const std::vector<std::string>& toUnload, bool keepLoaded = false);                    // if keepLoaded = true, then only the names in toUnload are kept
    void unload();                                                                                     // unloads everything


    protected :



    private :

    std::map<std::string, R> m_ressources;
};



#endif // TEXTURE_LIST_HEADER


