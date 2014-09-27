

#ifndef HEADER_NIVEAU
#define HEADER_NIVEAU

#include "Jeu/Emetteur.h"
#include "Entrees/TableauEntrees.h"
#include <sstream>
#include <string>


class Niveau : public VartAbs
{
    public :

    Niveau();

    virtual void attribuer(std::istream& chaineNiveau, Entrees* entrees) = 0;

    virtual void MAJ();
    virtual bool detruire() const;
    virtual void afficherDans(AfficheurObjets& fenetre);

    protected :

    void ajouter(VartAbs* ajout);
    virtual void finirJeu();
    Entrees* m_entrees; // use-a

    private :

    boost::shared_ptr< TableauVart<VartAbs> > m_tableau15; // has-a
    bool m_fin;
};





#endif

