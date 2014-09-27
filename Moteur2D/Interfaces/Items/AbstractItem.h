


#ifndef ABSTRACT_MENU_ITEM_HEADER
#define ABSTRACT_MENU_ITEM_HEADER

#include "../../Graphic/AbstractDrawer.h"

const bool DRAW_ITEM_HITBOX = false;

namespace Menu
{

    enum Alignement
    {
        TopLeftCorner,
        MiddleTopSide,
        TopRightCorner,
        MiddleLeftSide,
        Center,
        MiddleRightSide,
        BottomLeftCorner,
        MiddleBottomSide,
        BottomRightCorner
    };


    class AbstractItem
    {
        public :

        AbstractItem(AbstractItem* parent = nullptr);
        void setParent(AbstractItem* parent);
        virtual ~AbstractItem();

        virtual void drawIn(AbstractDrawer& target, sf::Vector2f position, bool drawHitbox = DRAW_ITEM_HITBOX) const;
        virtual void drawInBox(AbstractDrawer& target, sf::FloatRect box, Alignement a = Center, bool drawHitbox = DRAW_ITEM_HITBOX) const;
        virtual sf::Vector2f size() const = 0;


        protected :

        virtual void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const = 0;
        virtual void drawHitboxIn(AbstractDrawer& target, sf::Vector2f position) const;
        virtual int hashToColor(float x) const;

        virtual void updateParentSize();
        virtual void updateOwnSize();


        private :

        AbstractItem* m_parent;
    };



    inline bool isLeft(Alignement a)
    {
        return (a == TopLeftCorner) || (a == MiddleLeftSide) || (a == BottomLeftCorner);
    }

    inline bool isRight(Alignement a)
    {
        return (a == TopRightCorner) || (a == MiddleRightSide) || (a == BottomRightCorner);
    }

    inline bool isVerticalMiddle(Alignement a)
    {
        return !(isLeft(a) || isRight(a));
    }

    inline bool isTop(Alignement a)
    {
        return (a == TopLeftCorner) || (a == MiddleTopSide) || (a == TopRightCorner);
    }

    inline bool isBottom(Alignement a)
    {
        return (a == BottomLeftCorner) || (a == MiddleBottomSide) || (a == BottomRightCorner);
    }

    inline bool isHorizontalMiddle(Alignement a)
    {
        return !(isTop(a) || isBottom(a));
    }

    inline bool isSide(Alignement a)
    {
        return (a == MiddleLeftSide) || (a == MiddleTopSide) || (a == MiddleRightSide) || (a == MiddleBottomSide);
    }

    inline bool isCorner(Alignement a)
    {
        return (a == TopLeftCorner) || (a == TopRightCorner) || (a == BottomLeftCorner) || (a == BottomRightCorner);
    }

}



#endif // ABSTRACT_MENU_ITEM_HEADER


