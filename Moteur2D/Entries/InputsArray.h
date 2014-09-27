/*

TableauEntrees.h

Cree par Olivier Faure

Sert à extraire les inputs de la classe sf::Event
*/

#ifndef TABLEAU_ENTREES
#define TABLEAU_ENTREES

#include <SFML/Graphics.hpp>
#include "AbstractInputsArray.h"



/*
Classe servant à mesurer précisément les entrées, sans gestion des events
*/
class Inputs : public AbstractInputs
{
    public :

    explicit Inputs(sf::Window* fenetre = nullptr, bool escapeMeansClose = true);
    void set(sf::Window* fenetre, bool escapeMeansClose = true);

    bool closeWindow() const;             // Vrai quand la fin du jeu a ete demandee
    sf::Vector2f cursor() const;          // Position du curseur

    void update(float ticks = 0);

    std::map<sf::Mouse::Button, bool>& mouseButtons();           // Liste des boutons presses
    std::map<sf::Keyboard::Key , bool>& keyboardButtons();       // Liste des touches pressees

    const std::map<sf::Mouse::Button, bool>& mouseButtons() const;
    const std::map<sf::Keyboard::Key , bool>& keyboardButtons() const;


    private :

    sf::Window* m_fenetre;  // use-a
    sf::Event m_event;

    std::map<sf::Mouse::Button, bool> t_boutonsSouris;
    std::map<sf::Keyboard::Key , bool> t_boutonsClavier;
    sf::Vector2f m_cursor;
    int m_molette;

    bool m_closeWindow;
    bool m_escapeMeansClose;

};




#endif



