


#include "ItemBox.h"



Menu::ItemBox::ItemBox(AbstractItem* item, Alignement a, float x_offset, float y_offset) : m_size(sf::Vector2f(0,0)), m_relative(true)
{
    setItem(item);
    setAlignement(a, x_offset, y_offset);
    setSize(sf::Vector2f(0,0), true);
}


void Menu::ItemBox::setItem(AbstractItem* item)
{
    m_item = std::shared_ptr<AbstractItem>(item);
    m_item->setParent(this);
    updateParentSize();
}

void Menu::ItemBox::setAlignement(Alignement a, float x_offset, float y_offset)
{
    m_align = a;
    m_gaps = sf::Vector2f(x_offset, y_offset);
}

void Menu::ItemBox::setSize(sf::Vector2f size, bool relative)
{
    m_size = size;
    m_relative = relative;
}


void Menu::ItemBox::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    if (m_item)
    {
        sf::FloatRect box(position.x + m_gaps.x, position.y + m_gaps.y, m_size.x - m_gaps.x, m_size.y - m_gaps.y);
        m_item->drawInBox(target, box, m_align, isHitboxDrawn);
    }
}

sf::Vector2f Menu::ItemBox::size() const
{
    if (m_relative && m_item)
    return m_size + m_item->size();

    else
    return m_size;
}




