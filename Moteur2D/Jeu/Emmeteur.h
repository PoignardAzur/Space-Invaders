

#ifndef HEADER_EMMETTEUR
#define HEADER_EMMETTEUR

#include "Vart.h"
#include "TableauVarts.h"
#include <SFML/Graphics.hpp>


namespace CtB
{

    template <typename T, typename P>
    class Emetteur
    {
        public :

        Emetteur();
        Emetteur(TableauVart<T>& cible, P& paraObjetEmis);//, int maxObjets = 0, bool recyclerDerniers = false);

        void attribuer(TableauVart<T>& cible, P& paraObjetEmis);
        void creer(sf::Vector2f position);


        protected :


        private :

        TableauVart<T>* m_cible; // uses a
        P* m_paraObjetEmis;      // uses a
    };


    template <typename T, typename P>
    Emetteur<T,P>::Emetteur() : m_cible(0), m_paraObjetEmis(0)
    { }

    template <typename T, typename P>
    Emetteur<T,P>::Emetteur(TableauVart<T>& cible, P& paraObjetEmis) :
    m_cible(&cible), m_paraObjetEmis(&paraObjetEmis)
    { }

    template <typename T, typename P>
    void Emetteur<T,P>::attribuer(TableauVart<T>& cible, P& paraObjetEmis)
    {
        m_cible = &cible;
        m_paraObjetEmis = &paraObjetEmis;
    }


    template <typename T, typename P>
    void Emetteur<T,P>::creer(sf::Vector2f position)
    {
        m_cible->ajouter(new T(*m_paraObjetEmis, position));
    }
}



#endif

