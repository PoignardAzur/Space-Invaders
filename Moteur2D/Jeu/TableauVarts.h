


#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS




#include "VartAbs.h"


template <typename T = VartAbs>
class TableauVart : public VartAbs
{
    public :

    TableauVart();

    void ajouter(T* nvart);
    inline const std::vector< boost::shared_ptr<T> >& tableau() const;
    inline std::vector< boost::shared_ptr<T> >& tableau();

    inline boost::shared_ptr<T> objetN(unsigned short lequel);
    inline const boost::shared_ptr<T> objetN(unsigned short lequel) const;
    inline unsigned short taille() const;


    protected :

    void enlever(int lequel);


    private :

    std::vector< boost::shared_ptr<T> > t_varts; //has a


    public :

    virtual void MAJ()
    {
        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            t_varts[i]->MAJ();
        }

        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            if ( t_varts[i]->detruire() )
            enlever(i);
        }
    }

    virtual bool detruire() const
    {
        return false;
    }

    virtual void afficherDans(AfficheurObjets& cible)
    {
        for (unsigned short i = 0; i < t_varts.size(); i++)
        {
            t_varts[i]->afficherDans(cible);
        }
    }
};






#ifndef SOURCE_VART_ABSTRAIT
#include "TableauVarts.cpp"
#endif

#endif

