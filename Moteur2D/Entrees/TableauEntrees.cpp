


#include "TableauEntrees.h"


void MajTouche::operator()(std::pair<const sf::Mouse::Button, Touche>& x)
{
    if (x.second == Pressee)
    x.second = Activee;

    if (x.second == Lachee)
    x.second = Desactivee;
}

void MajTouche::operator()(std::pair<const sf::Keyboard::Key, Touche>& x)
{
    if (x.second == Pressee)
    x.second = Activee;

    if (x.second == Lachee)
    x.second = Desactivee;
}






Entrees::Entrees(sf::Window* fenetre) : m_fenetre(fenetre), m_fin(false)
{

}

bool Entrees::fini()
{
    return m_fin;
}

sf::Vector2f Entrees::curseur()
{
    return m_curseur;
}

void Entrees::MAJ()
{
    if (!m_fenetre)
    return;

    m_molette = 0;
    for_each(t_boutonsSouris.begin(), t_boutonsSouris.end(), majClavier);
    for_each(t_boutonsClavier.begin(), t_boutonsClavier.end(), majClavier);

    while (m_fenetre->pollEvent(m_event))
    {
        switch(m_event.type)
        {
            case sf::Event::MouseWheelMoved :
            m_molette += m_event.mouseWheel.delta;
            break;

            case sf::Event::MouseButtonPressed :
            t_boutonsSouris[m_event.mouseButton.button] = Pressee;
            break;

            case sf::Event::MouseButtonReleased :
            t_boutonsSouris[m_event.mouseButton.button] = Lachee;
            break;

            case sf::Event::KeyPressed :
            t_boutonsClavier[m_event.key.code] = Pressee;
            if (m_event.key.code == sf::Keyboard::Escape)
            m_fin = true;
            break;

            case sf::Event::KeyReleased :
            t_boutonsClavier[m_event.key.code] = Lachee;
            break;


            case sf::Event::MouseMoved :
            m_curseur.x = m_event.mouseMove.x;
            m_curseur.y = m_event.mouseMove.y;
            break;

            case sf::Event::Closed :
            m_fin = true;
            break;

            default :

            break;
        }
    }
}

std::map<sf::Mouse::Button, Touche>& Entrees::boutonsSouris()
{
    return t_boutonsSouris;
}

std::map<sf::Keyboard::Key , Touche> Entrees::boutonsClavier()
{
    return t_boutonsClavier;
}