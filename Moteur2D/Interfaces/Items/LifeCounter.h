



#ifndef MENU_LIFE_COUNTER_HEADER
#define MENU_LIFE_COUNTER_HEADER

#include "ItemGrid.h"
#include "ItemBox.h"
#include "Sprite.h"
#include "Counter.h"



namespace Menu
{

    class LifeCounter : public AbstractItem
    {
        public :

        LifeCounter();

        void setValue(int n);
        void setBounds(int maxDrawable, int max);
//        void setBase(int base);

        void setFont(const sf::Font* f, unsigned int charSize = DEFAULT_FONT_SIZE);
        void setColor(const sf::Color& c);
        void setRightAligned(bool rightAligned);
        void setSprite(const sf::Sprite& spr);

        void setGaps(float gap);
        sf::Vector2f size() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        ItemGrid m_grid; // use-a

        int m_count;
        int m_maxDrawable;

        std::shared_ptr<Sprite> m_lifeSprite;
        std::shared_ptr<Text> m_cross;
        std::shared_ptr<Counter> m_counter;

        float m_gap;
        bool m_rightAligned;

        void updateGrid();
    };


}



#endif // MENU_LIFE_COUNTER_HEADER


