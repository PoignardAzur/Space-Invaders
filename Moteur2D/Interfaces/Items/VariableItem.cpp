


#include "VariableItem.h"


Menu::VariableItem::VariableItem()
{

}

Menu::VariableItem::VariableItem(const std::vector<std::shared_ptr<AbstractItem>>& items, size_t selectedOne, ItemSize s)
{
    setItems(items, selectedOne);
    setSize(s);
}

void Menu::VariableItem::addItem(AbstractItem* item)
{
    m_items.push_back(std::shared_ptr<AbstractItem>(item));
}

void Menu::VariableItem::setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, size_t selectedOne)
{
    m_items = items;
    m_drawnItem = selectedOne;
    setSize(m_size);
}

const std::vector<std::shared_ptr<Menu::AbstractItem>>& Menu::VariableItem::getItems() const
{
    return m_items;
}

void Menu::VariableItem::selectItem(size_t n)
{
    m_drawnItem = n;
}

size_t Menu::VariableItem::itemSelected() const
{
    return m_drawnItem;
}


void Menu::VariableItem::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_items[m_drawnItem]->drawIn(target, position, isHitboxDrawn);
}

sf::Vector2f Menu::VariableItem::size() const
{
    if (m_size == Dynamic)
    return m_items[m_drawnItem]->size();

/// else
    return m_sizeValue;
}


void Menu::VariableItem::setSize(ItemSize s)
{
    if (s == Dynamic)
    {
        updateParentSize();
        return;
    }

/// else

    for (auto& item : m_items)
    {
        if ( (item->size().x > m_sizeValue.x) == (s == MaximumOne) )
        m_sizeValue.x = item->size().x;

        if ( (item->size().y > m_sizeValue.y) == (s == MaximumOne) )
        m_sizeValue.y = item->size().y;
    }

    updateParentSize();
}











