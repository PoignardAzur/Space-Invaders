

#include "BoucleJeu.h"
//#include "Moteur2D/includes.h"

#define TITRE_FENETRE "Faudrait penser à modifier ce titre"

int main()
{
    try
    {

        sf::RenderWindow fenetre(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), TITRE_FENETRE);
        CtB::AfficheurObjets afficheur(&fenetre);

        BoucleJeu bigBrother(&afficheur, new CtB::Entrees(&fenetre));

        while (!bigBrother.finDuJeu())
        {
            bigBrother.MAJ();
        }

        return EXIT_SUCCESS;
    }

    catch (std::exception const& e)
    {
       std::cerr << "ERREUR : " << e.what() << std::endl;
       return EXIT_FAILURE;
    }

}

