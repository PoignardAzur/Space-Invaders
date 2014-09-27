

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "VartAbs.h"
#include "../Physique/ObjetPhysique.h"

namespace CtB
{

    class Vart : public VartAbs
    {
        public :

        class Parametres;

        Vart(Parametres& para);
        Vart(Parametres& para, sf::Vector2f position);

        virtual void MAJ();
        virtual bool detruire() const;
        virtual void afficherDans(AfficheurObjets&);


        protected :

        virtual void detruireObjet();


        private :

        bool m_detruit;

        boost::shared_ptr<ObjetAffichable> m_sprite; // has a
        boost::shared_ptr<ObjetPhysique>   m_hitbox; // has a
    };


}



#endif
