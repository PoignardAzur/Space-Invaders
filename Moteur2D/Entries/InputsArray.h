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
Les quatre etats possible d'une touche / d'un bouton. Pressee et Lachee
correspondent au moment precis ou le bouton change d'etat.
*/
enum KeyState
{
    Desactivee = 0, Pressee, Activee, Lachee
};

/*
Foncteur mettant à jour une touche, en "enlevant" les etats temporaires
*/
class UpdateKey
{
    public :

    void operator()(std::pair<const sf::Mouse::Button, KeyState>& x);
    void operator()(std::pair<const sf::Keyboard::Key, KeyState>& x);
};

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

    std::map<sf::Mouse::Button, KeyState>& mouseButtons();       // Liste des boutons presses
    std::map<sf::Keyboard::Key , KeyState>& keyboardButtons();     // Liste des touches pressees


    protected :

    sf::Window* m_fenetre;  // use-a
    sf::Event m_event;

    std::map<sf::Mouse::Button, KeyState> t_boutonsSouris;
    std::map<sf::Keyboard::Key , KeyState> t_boutonsClavier;
    sf::Vector2f m_curseur;
    int m_molette;
    bool m_fin;

    UpdateKey majClavier;

};




#endif


