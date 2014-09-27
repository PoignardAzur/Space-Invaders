

#include "ClassesProjet/BoucleJeu.h"
//#include "Moteur2D/includes.h"
//#include <Clock.hpp>

#define TITRE_FENETRE "TODO : Modifier ce titre"
#define FRAMERATE 60
//#define FRAME_SIZE 1.0f / FRAMERATE

int main()
{
    try
    {

        sf::RenderWindow* fenetre = new sf::RenderWindow(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), TITRE_FENETRE);
        fenetre->setFramerateLimit(FRAMERATE);
        BoucleJeu bigBrother(new Level, new Inputs(fenetre), fenetre);
        sf::Clock chrono;

        while (bigBrother.doContinue())
        {
            bigBrother.update(chrono.restart().asSeconds());
        }

        return EXIT_SUCCESS;
    }

    catch (std::exception const& e)
    {
       std::cerr << "ERREUR : " << e.what() << std::endl;
       return EXIT_FAILURE;
    }

}

