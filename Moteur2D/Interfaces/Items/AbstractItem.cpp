


#include "AbstractItem.h"


Menu::AbstractItem::AbstractItem(AbstractItem* parent)
{
    setParent(parent);
}

void Menu::AbstractItem::setParent(AbstractItem* parent)
{
    m_parent = parent;
}

void Menu::AbstractItem::drawIn(AbstractDrawer& target, sf::Vector2f position, bool drawHitbox) const
{
    if (drawHitbox)
    drawHitboxIn(target, position);

    drawImageIn(target, position, drawHitbox);
}


void Menu::AbstractItem::drawInBox(AbstractDrawer& target, sf::FloatRect box, Alignement a, bool drawHitbox) const
{
    sf::Vector2f position(box.left, box.top);

    if (isRight(a))
    position.x += box.width - size().x;

    if (isVerticalMiddle(a))
    position.x += (box.width - size().x) / 2;


    if (isBottom(a))
    position.y += box.height - size().y;

    if (isHorizontalMiddle(a))
    position.y += (box.height - size().y) / 2;

    drawIn(target, position, drawHitbox);
}


int Menu::AbstractItem::hashToColor(float x) const
{
    return static_cast<int>(x * 17) % 255;
}


void Menu::AbstractItem::drawHitboxIn(AbstractDrawer& target, sf::Vector2f position) const
{
    sf::RectangleShape hitbox(size());
    hitbox.setPosition(position);
    hitbox.setFillColor(sf::Color( hashToColor(position.x), hashToColor(position.y), hashToColor(size().x + size().y) ));

    target.draw(hitbox);
}



void Menu::AbstractItem::updateParentSize()
{
    if (m_parent)
    m_parent->updateOwnSize();
}

void Menu::AbstractItem::updateOwnSize()
{
    updateParentSize();
}

Menu::AbstractItem::~AbstractItem()
{

}





