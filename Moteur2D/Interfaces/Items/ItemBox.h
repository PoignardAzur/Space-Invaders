


#ifndef MENU_ITEM_BOX_HEADER
#define MENU_ITEM_BOX_HEADER

#include <memory>
#include "AbstractItem.h"

namespace Menu
{

    class ItemBox : public AbstractItem
    {
        public :

        explicit ItemBox(AbstractItem* item = nullptr, Alignement a = Center, float x_offset = 0, float y_offset = 0);

        void setItem(AbstractItem* item);
        void setAlignement(Alignement a, float x_offset, float y_offset);
        void setSize(sf::Vector2f size, bool relative = false);
        sf::Vector2f size() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        std::shared_ptr<AbstractItem> m_item;
        Alignement m_align;

        sf::Vector2f m_gaps;
        sf::Vector2f m_size;
        bool m_relative;
    };



}



#endif // MENU_ITEM_BOX_HEADER


