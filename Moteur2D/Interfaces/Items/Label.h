

#ifndef MENU_LABEL_HEADER
#define MENU_LABEL_HEADER

#include "Text.h"
#include <memory>

namespace Menu
{

    class Label : public AbstractItem
    {
        public :

        explicit Label(AbstractItem* item = nullptr, const std::string& str = "", bool horizontalAlignement = true, float gap = 0);

        void setItem(AbstractItem* item, const std::string& str);
        void setItem(AbstractItem* item);
        void setLabel(const std::string& str);
        void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
        void setColor(const sf::Color& c);

        void setAlignement(bool horizontal, float gap);
        sf::Vector2f size() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void setOwnSize();


        private :

        std::shared_ptr<AbstractItem> m_item;
        Text m_label;

        float m_gap;
        bool m_horizontalAlignement;

        sf::Vector2f m_size;
    };



}


#endif // MENU_LABEL_HEADER
