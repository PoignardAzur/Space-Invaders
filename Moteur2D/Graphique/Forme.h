

#ifndef HEADER_FORME_AFFICHABLE
#define HEADER_FORME_AFFICHABLE

#include "ObjetAffichable.h"




class FormeAffichable : public ObjetAffichable
{
    public :

    class Parametres;

    template <typename T>
    FormeAffichable(T& paraObjet);
    FormeAffichable(Parametres& paraObjet);

    sf::Shape& afficher();
    const sf::Shape& afficher() const;

    void deplacer(const sf::Vector2f& distance);

    protected :

    private :

    boost::shared_ptr<sf::Shape> m_sprite; // has-a

};




class FormeAffichable::Parametres
{
    protected :

    sf::Shape* m_forme;


    public :

    Parametres(sf::Shape* n_image) : m_forme(n_image)
    {

    }

    inline sf::Shape* afficher()
    {
        return m_forme;
    }

    inline const sf::Shape* afficher() const
    {
        return m_forme;
    }

};


template <typename T>
FormeAffichable::FormeAffichable(T& paraObjet)
{
    Parametres p0(paraObjet);
    m_sprite = p0.afficher();
}




#endif


