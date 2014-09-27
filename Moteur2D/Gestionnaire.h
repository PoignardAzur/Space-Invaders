

#ifndef HEADER_GESTIONNAIRE
#define HEADER_GESTIONNAIRE

#include "Jeu/Emmeteur.h"
#include "Jeu/Entrees/TableauEntrees.h"


namespace CtB
{

    class Gestionnaire
    {
        public :

        Gestionnaire(AfficheurObjets* cible = 0, Entrees* entrees = 0);

        virtual void MAJ();
        virtual bool finDuJeu() = 0;

        protected :

        void ajouter(VartAbs* ajout);
        Entrees& entreesFenetre();

        private :

        AfficheurObjets* m_fenetreCible; // use-a
        boost::shared_ptr< TableauVart<VartAbs> > m_tableau15; // has-a
        boost::shared_ptr<Entrees> m_entrees; // has-a

    };

}


#endif

