


#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS




#include "AbsVart.h"
#include <list>
#include <memory>



template <typename T = AbsVart>
class VartPusher
{
    public :

    virtual void add(T* vart) = 0;
};


template <typename T = AbsVart>
class VartArray : public std::list<std::shared_ptr<T>>, public VartPusher<T>
{
    public :

    ~VartArray();

    virtual void updateAll(float dt, bool delDeadVarts = true); // Quand le tableau est mis à jour, tous ses éléments le sont.
    virtual void drawAllIn(AbstractDrawer& cible); // Quand le tableau est affiche, tous ses éléments le sont.
    virtual void add(T* vart);

    virtual void deleteDeadVarts();


    private :

    typedef std::list<std::shared_ptr<T>> lpT;
};


template <typename T>
VartArray<T>::~VartArray()
{

}


template <typename T>
void VartArray<T>::updateAll(float dt, bool delDeadVarts)
{
    for (auto p = lpT::begin(); p != lpT::end(); ++p)
    {
        (*p)->update(dt);
    }

    if (delDeadVarts)
    deleteDeadVarts();
    /* we could just call erase(p) in the loop, but it could lead to
    problems should a Vart need variables from a deleted one */
}


template <typename T>
void VartArray<T>::drawAllIn(AbstractDrawer& cible)
{
    for (auto p = lpT::begin(); p != lpT::end(); ++p)
    {
        (*p)->drawIn(cible);
    }
}


template <typename T>
void VartArray<T>::add(T* vart)
{
    lpT::push_back(std::shared_ptr<T>(vart));
}



template <typename T>
void VartArray<T>::deleteDeadVarts()
{
    lpT::remove_if([](const std::shared_ptr<T>& p) { return p->doDelete(); });
/*  for (auto p = lpT::begin(); l != lpT::end(); )
    {
        if ((*p)->doDelete())
        p = lpT::erase(p);

        else
        p++;
    }*/
}




#endif

