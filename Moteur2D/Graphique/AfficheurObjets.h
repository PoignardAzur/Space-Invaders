


#ifndef HEADER_AFFICHEUR_OBJETS
#define HEADER_AFFICHEUR_OBJETS

#include "ObjetAffichable.h"
#include "ParametresAffichage.h"


namespace CtB
{

    class AfficheurObjets
    {
        public :

        AfficheurObjets(sf::RenderTarget* cible);

        void afficher(const ObjetAffichable& objet, const ParametresAffichage& para);
        void afficher(const ObjetAffichable& objet);

        protected :

        private :

        boost::shared_ptr<sf::RenderTarget> m_fenetreCible; // has-a
    };



}

#endif

