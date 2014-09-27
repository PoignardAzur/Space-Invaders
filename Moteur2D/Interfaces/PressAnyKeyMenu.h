

#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "AbstractGameInterface.h"



template <typename In>
class PressAnyKeyMenu : public AbstractGameInterface<In>
{
    public :

    virtual void drawIn(AbstractDrawer& window) = 0;

    virtual void update(const In& inputData)
    {
        if (AbstractGameInterface<In>::getInputs()->pressedKeyboardButtons().size()
         || AbstractGameInterface<In>::getInputs()->pressedMouseButtons().size() )

        AbstractGameInterface<In>::deleteLater();
    }


    AbstractGameInterface<In>* toLoad()
    {
        return nullptr;
    }
};




#endif

