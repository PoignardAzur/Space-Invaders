/*

TableauEntrees.h

Cree par Olivier Faure

Sert à extraire les inputs de la classe sf::Event
*/

#ifndef TABLEAU_ENTREES
#define TABLEAU_ENTREES

#include <map>
#include <SFML/Graphics.hpp>


/*
Classe servant à mesurer précisément les entrées, sans gestion des events
*/
class Inputs
{
    public :

    Inputs(sf::Window* fenetre = 0);

    bool endGame(); // Vrai quand la fin du jeu a ete demandee
    sf::Vector2f cursor(); // Position du curseur

    void update();

    std::map<sf::Mouse::Button, bool>& mouseButtons();       // Liste des boutons presses
    std::map<sf::Keyboard::Key , bool>& keyboardButtons();     // Liste des touches pressees


    protected :

    sf::Window* m_fenetre;  // use-a
    sf::Event m_event;

    std::map<sf::Mouse::Button, bool> t_boutonsSouris;
    std::map<sf::Keyboard::Key , bool> t_boutonsClavier;
    sf::Vector2f m_curseur;
    int m_molette;
    bool m_fin;

};




#endif


