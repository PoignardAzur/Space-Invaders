

#include "ItemStack.h"


Menu::ItemStack::ItemStack()
{

}

Menu::ItemStack::ItemStack(const std::vector<std::pair<AbsItemPtr, Alignement>>& items, bool sizeIsMax)
{
    setItems(items, sizeIsMax);
}

void Menu::ItemStack::setItems(const std::vector<std::pair<AbsItemPtr, Alignement>>& items, bool sizeIsMax)
{
    for (auto item : items)
    {
        item.first->setParent(this);
    }

    m_items = items;
    m_sizeIsMax = sizeIsMax;

    updateOwnSize();
}

void Menu::ItemStack::addItem(AbstractItem* item, Alignement align)
{
    m_items.push_back(std::pair<AbsItemPtr, Alignement>(AbsItemPtr(item), align));
    item->setParent(this);
    updateOwnSize();
}

void Menu::ItemStack::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, m_size.x, m_size.y);

    for (auto const& alignedItem : m_items)
    {
        alignedItem.first->drawInBox(target, box, alignedItem.second, isHitboxDrawn);
    }
}

sf::Vector2f Menu::ItemStack::size() const
{
    return m_size;
}

void Menu::ItemStack::updateOwnSize()
{
    if (m_sizeIsMax)
    {
        m_size = sf::Vector2f(0,0);

        for (auto const& alignedItem : m_items)
        {
            m_size.x = m_size.x > alignedItem.first->size().x ? m_size.x : alignedItem.first->size().x;
            m_size.y = m_size.y > alignedItem.first->size().y ? m_size.y : alignedItem.first->size().y;
        }
    }

    else if (m_items.size())
    {
        m_size = m_items[0].first->size();

        for (auto const& alignedItem : m_items)
        {
            m_size.x = m_size.x < alignedItem.first->size().x ? m_size.x : alignedItem.first->size().x;
            m_size.y = m_size.y < alignedItem.first->size().y ? m_size.y : alignedItem.first->size().y;
        }
    }

    else
    m_size = sf::Vector2f(0,0);

    updateParentSize();
}




