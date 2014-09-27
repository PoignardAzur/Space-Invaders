


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "ObjetAffichable.h"
#include "ParametresAffichage.h"

#define LIMITE_NOMBRE_FPS 60


namespace CtB
{

    class AfficheurObjets
    {
        public :

        AfficheurObjets(sf::RenderWindow* cible);

        void afficher(const ObjetAffichable& objet, const ParametresAffichage& para);
        void afficher(const ObjetAffichable& objet);

        void effacer();
        void afficherTout();

        protected :

        private :

        sf::RenderWindow* m_fenetreCible; /// use-a
    };



}

#endif

