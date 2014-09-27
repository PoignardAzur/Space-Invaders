


#ifndef HEADER_MOUVEMENT
#define HEADER_MOUVEMENT

#include <SFML/Graphics.hpp>


namespace CtB
{

    class Mouvement
    {
        public :

        Mouvement( sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f vitesse = sf::Vector2f(0,0) );

        void MAJ();
        virtual void changerVitesse(sf::Vector2f nvitesse, bool relatif = false);
        void deplacer(sf::Vector2f nposition, bool relatif = false);

        sf::Vector2f position() const;
        sf::Vector2f vitesse() const;


        protected :


        private :

        sf::Vector2f m_position;
        sf::Vector2f m_vitesse;

    };


}




#endif


