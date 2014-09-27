

#include "ClassesProjet/BoucleJeu.h"
//#include "Moteur2D/includes.h"
#include <iostream>

inline int catchError(const char* e)
{
    std::cerr << "ERROR : " << e << std::endl;
    return EXIT_FAILURE;
}

int main(int argc, char** argv)
{
    try
    {
        sf::RenderWindow* fenetre = new sf::RenderWindow(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), TITRE_FENETRE);

        fenetre->setFramerateLimit(FRAMERATE);
        BoucleJeu bigBrother(new Inputs(fenetre), fenetre);
        sf::Clock chronos;

        while (bigBrother.doContinue())
        {
            bigBrother.update(chronos.restart().asSeconds());
            fenetre->display();
        }

        fenetre->close();
/*        std::cout << "Score : " << bigBrother.finalScore() << " points."
        << std::endl << "Appuyer sur entree pour continuer" << std::endl;
//        << std::endl << "Press enter to continue" << std::endl;
//        << std::endl; return EXIT_SUCCESS;
        std::string x;
       // std::getline(std::cin, x);
*/
        return EXIT_SUCCESS;
    }

    catch (std::string const& e)
    {
        return catchError(e.c_str());
    }

    catch (const char* e)
    {
        return catchError(e);
    }

    catch (std::exception const& e)
    {
        return catchError(e.what());
    }

    catch (...)
    {
        return catchError("Non specified error occured");
    }

}

