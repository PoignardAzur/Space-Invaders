



#ifndef HEADER_HITBOX
#define HEADER_HITBOX

#include <vector>
#include <SFML/Graphics.hpp>
//#include <SFML/Rect.hpp>


namespace CtB
{

    class Hitbox
    {
        private :

        sf::IntRect m_rectangle;

        public :

        Hitbox(sf::IntRect parametres) : m_rectangle(parametres) {}

        const sf::IntRect& rectangle() const
        {
            return m_rectangle;
        }

        sf::IntRect& rectangle()
        {
            return m_rectangle;
        }

        void decaler(sf::Vector2f translation)
        {
            m_rectangle.left += translation.x;
            m_rectangle.top += translation.y;
        }

        protected :

    };

    bool collision(const sf::IntRect& rectangle1, const sf::IntRect& rectangle2);
    bool collision(const sf::Vector2f& rectangle1, const sf::IntRect& rectangle2);
    inline bool collision(const sf::IntRect& rectangle1, const sf::Vector2f& rectangle2);
    bool collision(const Hitbox& rectangle1, const Hitbox& rectangle2);
}




#endif

