

#ifndef HEADER_OBJET_AFFICHABLE
#define HEADER_OBJET_AFFICHABLE

#include <SFML/Graphics.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>


namespace CtB
{

    class ObjetAffichable
    {
        public :

        class Parametres;

        ObjetAffichable(const Parametres& paraObjet);

        protected :



        private :

        sf::Sprite m_sprite;


        public :

        inline sf::Sprite& sprite()
        {
            return m_sprite;
        }

        inline const sf::Sprite& sprite() const
        {
            return m_sprite;
        }

    };




    class ObjetAffichable::Parametres
    {
        protected :

        sf::Texture* m_image;


        public :

        Parametres(sf::Texture* n_image) : m_image(n_image)
        {

        }

        inline sf::Texture* adresseImage()
        {
            return m_image;
        }

        inline const sf::Texture* adresseImage() const
        {
            return m_image;
        }

    };



}

#endif

