
#include "Label.h"


Menu::Label::Label(AbstractItem* item, const std::string& str, bool horizontalAlignement, float gap)
{
    setItem(item, str);
    setAlignement(horizontalAlignement, gap);
}

void Menu::Label::setItem(AbstractItem* item, const std::string& str)
{
    setItem(item);
    setLabel(str);
}

void Menu::Label::setItem(AbstractItem* item)
{
    m_item = std::shared_ptr<AbstractItem>(item);

    if (m_item)
    m_item->setParent(this);
    setOwnSize();
}

void Menu::Label::setLabel(const std::string& str)
{
    m_label.setString(str);
    setOwnSize();
}

void Menu::Label::setFont(const sf::Font* f, unsigned int charSize)
{
    m_label.setFont(f, charSize);
    setOwnSize();
}

void Menu::Label::setColor(const sf::Color& c)
{
    m_label.setColor(c);
}

void Menu::Label::setAlignement(bool horizontal, float gap)
{
    m_horizontalAlignement = horizontal;
    m_gap = gap;

    setOwnSize();
}

sf::Vector2f Menu::Label::size() const
{
    return m_size;
}

void Menu::Label::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, size().x, size().y);

    if (m_horizontalAlignement)
    {
        m_label.drawInBox(target, box, BottomLeftCorner, isHitboxDrawn);

        if (m_item)
        m_item->drawInBox(target, box, BottomRightCorner, isHitboxDrawn);
    }

    else
    {
        m_label.drawInBox(target, box, TopLeftCorner, isHitboxDrawn);

        if (m_item)
        m_item->drawInBox(target, box, BottomLeftCorner, isHitboxDrawn);
    }
}

void Menu::Label::setOwnSize()
{
    if (!m_item)
    m_size = m_label.size();

    else if (m_horizontalAlignement)
    {
        m_size.x = m_label.size().x + m_item->size().x + m_gap;
        m_size.y = m_label.size().y > m_item->size().y ? m_label.size().y : m_item->size().y;
    }

    else
    {
        m_size.x = m_label.size().x > m_item->size().x ? m_label.size().x : m_item->size().x;
        m_size.y = m_label.size().y + m_item->size().y + m_gap;
    }
}


