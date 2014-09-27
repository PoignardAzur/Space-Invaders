


#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS




#include "AbsVart.h"


template <typename T = AbsVart>
class VartArray : public AbsVart
{
    public :

    VartArray();

    void add(T* nvart);
    inline const std::vector< boost::shared_ptr<T> >& array() const;
    inline std::vector< boost::shared_ptr<T> >& array();

    inline boost::shared_ptr<T> objectN(unsigned short lequel);
    inline const boost::shared_ptr<T> objectN(unsigned short lequel) const;
    inline unsigned short size() const;
    inline void clear();


    protected :

    void remove(int lequel);

    virtual void deleteVarts()
    {
        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            if ( t_varts[i]->doDelete() )
            remove(i);
        }
    }

    private :

    std::vector< boost::shared_ptr<T> > t_varts; //has a


    public :

    virtual void update(float tickSize) // Quand le tableau est mis à jour, tous ses éléments le sont.
    {
        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            t_varts[i]->update(tickSize);
        }

        deleteVarts();
    }

    virtual bool doDelete() const // Dans un tableau basique, pas de raison de le delete.
    {
        return false;
    }

    virtual void drawIn(AbstractDrawer& cible) // Quand le tableau est affiche, tous ses éléments le sont.
    {
        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            t_varts[i]->drawIn(cible);
        }
    }
};




template <typename T>
VartArray<T>::VartArray()
{

}




template <typename T>
void VartArray<T>::add(T* nvart)
{
    boost::shared_ptr<T> pointeurVart(nvart);
    t_varts.push_back(pointeurVart);
}


template <typename T>
inline const std::vector< boost::shared_ptr<T> >& VartArray<T>::array() const
{
    return /*const_cast<const std::vector< boost::shared_ptr<T> >&>*/ t_varts;
}


template <typename T>
inline std::vector< boost::shared_ptr<T> >& VartArray<T>::array() // getter basique
{
    return t_varts;
}


template <typename T>
inline void VartArray<T>::clear()
{
    t_varts.clear();
}

template <typename T>
inline boost::shared_ptr<T> VartArray<T>::objectN(unsigned short lequel)
{
    return t_varts[lequel];
}


template <typename T>
inline const boost::shared_ptr<T> VartArray<T>::objectN(unsigned short lequel) const
{
    return t_varts[lequel];
}

template <typename T>
inline unsigned short VartArray<T>::size() const
{
    return t_varts.size();
}



template <typename T>
void VartArray<T>::remove(int lequel)
{
    t_varts.erase(t_varts.begin() + lequel);
}




#endif

