

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "VartAbs.h"
#include "../Graphique/Sprite.h"
#include "./Physique/ObjetPhysique.h"




class ParaVart;

class Vart : public VartAbs, public ObjetPhysique
{
    public :

    Vart(const ParaVart& para);
    Vart(const ParaVart& para, sf::Vector2f position);

    virtual void MAJ();
    virtual bool detruire() const;
    virtual void afficherDans(AfficheurObjets&);


    protected :

    virtual void detruireObjet();
    void attribuer(Sprite* para);
//        void attribuer(const ParaVart& para);
//        void attribuer(ObjetPhysique* para);

    private :

    bool m_detruit;
    boost::shared_ptr<Sprite> m_sprite; // has a
};


#include "ParametresVart.h"


#endif
