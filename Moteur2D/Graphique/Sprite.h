

#ifndef HEADER_SPRITE
#define HEADER_SPRITE

#include "ObjetAffichable.h"


namespace CtB
{

    class Sprite : public ObjetAffichable
    {
        public :

        class Parametres;

        Sprite(const Parametres& paraObjet);

        sf::Sprite& afficher();
        const sf::Sprite& afficher() const;

        void deplacer(const sf::Vector2f& distance);

        protected :

        private :

        sf::Sprite m_sprite;

    };




    class Sprite::Parametres
    {
        protected :

        const sf::Texture* m_image;


        public :

        Parametres(const sf::Texture* n_image) : m_image(n_image)
        {

        }

        inline const sf::Texture* adresseImage() const
        {
            return m_image;
        }

    };

    typedef Sprite::Parametres pSpr;



}


#endif

