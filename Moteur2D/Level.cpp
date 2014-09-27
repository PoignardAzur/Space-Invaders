

#include "Level.h"
// Fuuuuuuuuuuuuuuuuu


Level::Level() : m_tableau15(new VartArray<AbsVart>())
{

}

 void Level::attribuer(Inputs* entrees)
{
    m_entrees = entrees;
}

void Level::update(float tickSize)
{
    m_tableau15->update(tickSize);
}

void Level::drawIn(AbstractDrawer& fenetre)
{
    m_tableau15->drawIn(fenetre);
}

void Level::clear()
{
    m_tableau15->clear();
}



void Level::add(AbsVart* ajout)
{
    if (m_tableau15)
    {
        m_tableau15->add(ajout);
    }
}

bool Level::deleteLevel() const
{
    return m_fin;
}


void Level::finirJeu()
{
    m_fin = true;
}

