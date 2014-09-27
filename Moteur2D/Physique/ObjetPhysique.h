


#ifndef HEADER_OBJET_PHYSIQUE
#define HEADER_OBJET_PHYSIQUE

#include "Hitbox.h"
#include "Mouvement.h"


namespace CtB
{

    class ObjetPhysique : public Mouvement
    {
        private :

        Hitbox m_boite;

        public :

        ObjetPhysique(sf::IntRect parametres, sf::Vector2f position = sf::Vector2f(0,0), sf::Vector2f vitesse = sf::Vector2f(0,0)) :
        Mouvement(position, vitesse), m_boite(parametres)
        { }

        friend bool collision(const ObjetPhysique& objet1, const ObjetPhysique& objet2);

        protected :

        void aligner(bool reset);
    };

    bool collision(const ObjetPhysique& objet1, const ObjetPhysique& objet2);

}



#endif

