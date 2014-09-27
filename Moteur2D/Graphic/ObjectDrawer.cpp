

#include "ObjectDrawer.h"



ObjectDrawer::ObjectDrawer(sf::RenderTarget* cible) : m_fenetreCible(cible)
{

}

sf::RenderTarget& ObjectDrawer::target()
{
    return *m_fenetreCible;
}

