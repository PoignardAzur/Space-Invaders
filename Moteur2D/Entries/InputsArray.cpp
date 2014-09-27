


#include "InputsArray.h"


Inputs::Inputs(sf::Window* fenetre) : m_fenetre(fenetre), m_fin(false)
{

}

bool Inputs::endGame()
{
    return m_fin;
}

sf::Vector2f Inputs::cursor()
{
    return m_curseur;
}

void Inputs::update()
{
    if (!m_fenetre)
    return;

    m_molette = 0;

    while (m_fenetre->pollEvent(m_event))
    {
        switch(m_event.type)
        {
            case sf::Event::MouseWheelMoved : // Enregistre le nombre de tics de molettes (à priori 1)
            m_molette += m_event.mouseWheel.delta;
            break;

            case sf::Event::MouseButtonPressed : // Enregistre l'appui d'une touche (de souris)
            t_boutonsSouris[m_event.mouseButton.button] = true;
            break;

            case sf::Event::MouseButtonReleased : // Met fin à l'appui d'une touche (de souris)
            t_boutonsSouris[m_event.mouseButton.button] = false;
            break;

            case sf::Event::KeyPressed : // Pareil, mais sans les (de souris)
            t_boutonsClavier[m_event.key.code] = true;
            if (m_event.key.code == sf::Keyboard::Escape) // L'appui sur echap met fin au jeu.
            m_fin = true;
            break;

            case sf::Event::KeyReleased : // Encore pareil
            t_boutonsClavier[m_event.key.code] = false;
            break;


            case sf::Event::MouseMoved : // Enregistre la nouvelle position de la souris (pas de mouvement relatif)
            m_curseur.x = m_event.mouseMove.x;
            m_curseur.y = m_event.mouseMove.y;
            break;

            case sf::Event::Closed : // Détecte les tentatives de fermeture de fenetre
            m_fin = true;
            break;

            default :

            break;
        }
    }
}

std::map<sf::Mouse::Button, bool>& Inputs::mouseButtons()
{
    return t_boutonsSouris;
}

std::map<sf::Keyboard::Key, bool>& Inputs::keyboardButtons()
{
    return t_boutonsClavier;
}
