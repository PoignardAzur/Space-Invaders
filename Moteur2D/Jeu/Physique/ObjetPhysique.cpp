


#include "ObjetPhysique.h"



ObjetPhysique::ObjetPhysique(sf::IntRect parametres, sf::Vector2f position, sf::Vector2f vitesse) :
Mouvement(position, vitesse), m_boite(parametres)
{ }


sf::Vector2f ObjetPhysique::decalage() const
{
    return sf::Vector2f(m_boite.left, m_boite.top);
}


sf::IntRect ObjetPhysique::boiteAbsolue() const
{
    return m_boite;
}

sf::IntRect ObjetPhysique::boiteRelative() const
{
    return sf::IntRect(m_boite.left + position().x, m_boite.top + position().y, m_boite.height, m_boite.width);
}


bool testerCollision(const ObjetPhysique& objet1, const ObjetPhysique& objet2)
{
    return testerCollision(objet1.boiteAbsolue(), objet2.boiteAbsolue());
}





