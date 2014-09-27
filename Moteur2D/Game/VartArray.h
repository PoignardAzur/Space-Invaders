


#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS




#include "AbsVart.h"
#include <deque>
#include <memory>


template <typename T = AbsVart>
class VartArray : public std::deque<std::shared_ptr<T>>
{
    public :

    ~VartArray();

    virtual void updateAll(float tickSize, bool delDeadVarts = true); // Quand le tableau est mis à jour, tous ses éléments le sont.
    virtual void drawAllIn(AbstractDrawer& cible); // Quand le tableau est affiche, tous ses éléments le sont.
    virtual void add(T* vart);

    virtual void deleteDeadVarts();


    private :

    typedef std::deque<std::shared_ptr<T>> dpT;
//  using std::deque<std::shared_ptr<T>>::deque();
};


template <typename T>
VartArray<T>::~VartArray()
{

}


template <typename T>
void VartArray<T>::updateAll(float tickSize, bool delDeadVarts)
{
    for (auto p = dpT::begin(); p != dpT::end(); ++p)
    {
        (*p)->update(tickSize);
    }

    if (delDeadVarts)
    deleteDeadVarts();
    /* we could just call erase(p) in the loop, but it could lead to
    problems should a Vart need variables from a deleted one */
}


template <typename T>
void VartArray<T>::drawAllIn(AbstractDrawer& cible)
{
    for (auto p = dpT::begin(); p != dpT::end(); ++p)
    {
        (*p)->drawIn(cible);
    }
}


template <typename T>
void VartArray<T>::add(T* vart)
{
    dpT::push_back(std::shared_ptr<T>(vart));
}



template <typename T>
void VartArray<T>::deleteDeadVarts()
{
    for (auto p = dpT::begin(); p != dpT::end(); )
    {
        if ((*p)->doDelete())
        p = dpT::erase(p);

        else
        p++;
    }
}




#endif

