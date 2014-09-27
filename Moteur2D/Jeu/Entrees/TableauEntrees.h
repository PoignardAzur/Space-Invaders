/*

TableauEntrees.h

Cree par Olivier Faure

Sert à extraire les inputs de la classe sf::Event
*/

#ifndef TABLEAU_ENTREES
#define TABLEAU_ENTREES

#include <map>
#include <SFML/Graphics.hpp>


namespace CtB
{

    enum Touche
    {
        Desactivee, Pressee, Activee, Lachee
    };

    class MajTouche
    {
        public :

        void operator()(std::pair<const sf::Mouse::Button, CtB::Touche>& x);
        void operator()(std::pair<const sf::Keyboard::Key, CtB::Touche>& x);
    };


    class Entrees
    {
        public :

        Entrees(sf::Window* fenetre = 0);

        bool fini();
        sf::Vector2f curseur();

        void MAJ();

        std::map<sf::Mouse::Button, Touche>& boutonsSouris();
        std::map<sf::Keyboard::Key , Touche> boutonsClavier();


        protected :

        sf::Window* m_fenetre;  // use-a
        sf::Event m_event;

        std::map<sf::Mouse::Button, Touche> t_boutonsSouris;
        std::map<sf::Keyboard::Key , Touche> t_boutonsClavier;
        sf::Vector2f m_curseur;
        int m_molette;
        bool m_fin;

        MajTouche majClavier;

    };

}


#endif


