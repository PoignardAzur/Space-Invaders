


#ifndef HEADER_OBJET_PHYSIQUE
#define HEADER_OBJET_PHYSIQUE

#include <SFML/Graphics.hpp>
#include "Mouvement.h"

#define PT_NUL sf::Vector2f(0,0)
#define RECT_NUL sf::IntRect(0,0,0,0)


class ObjetPhysique : public Mouvement
{
    public :

    ObjetPhysique(sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL);

    sf::IntRect boiteAbsolue() const;
    sf::IntRect boiteRelative() const;
    sf::Vector2f decalage() const;
    void aligner(bool reset);

    private :

    sf::IntRect m_boite;
};


bool testerCollision(const ObjetPhysique& objet1, const ObjetPhysique& objet2);



#endif

