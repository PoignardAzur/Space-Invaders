

#include "ObjectDrawer.h"



ObjectDrawer::ObjectDrawer(sf::RenderWindow* cible) : m_fenetreCible(cible)
{
//    m_fenetreCible->setFramerateLimit(LIMITE_NOMBRE_FPS); // Deplacer ca autre part ?
}

sf::RenderTarget& ObjectDrawer::target()
{
    return *m_fenetreCible;
}


void ObjectDrawer::display()
{
    m_fenetreCible->display();
}


