
#ifndef HEADER_VART_ABSTRAIT
#include "TableauVarts.h"
#endif

#ifndef SOURCE_VART_ABSTRAIT
#define SOURCE_VART_ABSTRAIT



template <typename T>
CtB::TableauVart<T>::TableauVart()
{

}




template <typename T>
void CtB::TableauVart<T>::ajouter(T* nvart)
{
    boost::shared_ptr<T> pointeurVart(nvart);
    t_varts.push_back(pointeurVart);
}


template <typename T>
inline const std::vector< boost::shared_ptr<T> >& CtB::TableauVart<T>::tableau() const
{
    return /*const_cast<const std::vector< boost::shared_ptr<T> >&>*/ t_varts;
}


template <typename T>
inline std::vector< boost::shared_ptr<T> >& CtB::TableauVart<T>::tableau()
{
    return t_varts;
}

template <typename T>
inline boost::shared_ptr<T> CtB::TableauVart<T>::objetN(unsigned short lequel)
{
    return t_varts[lequel];
}


template <typename T>
inline const boost::shared_ptr<T> CtB::TableauVart<T>::objetN(unsigned short lequel) const
{
    return t_varts[lequel];
}

template <typename T>
inline unsigned short CtB::TableauVart<T>::taille() const
{
    return t_varts.size();
}



template <typename T>
void CtB::TableauVart<T>::enlever(int lequel)
{
    t_varts.erase(t_varts.begin() + lequel);
}



#endif
