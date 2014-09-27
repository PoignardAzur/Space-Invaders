

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "VartAbs.h"
#include "../Graphique/Sprite.h"
#include "../Physique/ObjetPhysique.h"


namespace CtB
{
    class ParaVart;

    class Vart : public VartAbs
    {
        public :

        Vart();
        Vart(const ParaVart& para);
        Vart(const ParaVart& para, sf::Vector2f position);

        virtual void MAJ();
        virtual bool detruire() const;
        virtual void afficherDans(AfficheurObjets&);


        protected :

        virtual void detruireObjet();

        void attribuer(const ParaVart& para);
        void attribuer(Sprite* para);
        void attribuer(ObjetPhysique* para);


   //     private :

        bool m_detruit;

        boost::shared_ptr<Sprite> m_sprite; // has a
        boost::shared_ptr<ObjetPhysique>   m_hitbox; // has a

    };



}


#include "ParametresVart.h"


#endif
