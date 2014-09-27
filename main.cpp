

#include "BoucleJeu.h"
#include <fstream>
#include "NiveauShoot.h"
//#include "Moteur2D/includes.h"

#define TITRE_FENETRE "Faudrait penser à modifier ce titre"
#define ADRESSE_FICHIER "Niveau.txt"


int main()
{
    try
    {
        sf::RenderWindow fenetre(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), TITRE_FENETRE);
        std::ifstream fichier(ADRESSE_FICHIER);
        Entrees* p_entrees = new Entrees(&fenetre);
        Gestionnaire boucle(new NiveauShoot(fichier, p_entrees), p_entrees, &fenetre);

        while (boucle.continuer())
        {
            boucle.MAJ();
        }

        return EXIT_SUCCESS;
    }

    catch (std::exception const& e)
    {
       std::cerr << "ERREUR : " << e.what() << std::endl;
       return EXIT_FAILURE;
    }

}

