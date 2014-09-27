
#ifndef ABSTRACT_INPUT_ARRAY_HEADER
#define ABSTRACT_INPUT_ARRAY_HEADER

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>



class AbstractInputs
{
    public :

    virtual ~AbstractInputs() {}

    virtual bool closeWindow() const = 0;                        // true when the window must be closed or the escape key is pressed
    virtual sf::Vector2f cursor() const = 0;                 // cursor position

    virtual void update(float ticks = 0) = 0;              // the number of ticks isn't really important

    virtual std::map<sf::Mouse::Button, bool>& mouseButtons() = 0;                   // list of all mouse buttons
    virtual std::map<sf::Keyboard::Key , bool>& keyboardButtons() = 0;               // list of all keyboard keys

    virtual const std::map<sf::Mouse::Button, bool>& mouseButtons() const;                   // list of all mouse buttons
    virtual const std::map<sf::Keyboard::Key , bool>& keyboardButtons() const;               // list of all keyboard keys

    const std::vector<sf::Mouse::Button>& pressedMouseButtons() const;          // list of pressed mouse buttons
    const std::vector<sf::Keyboard::Key>& pressedKeyboardButtons() const;       // list of pressed keyboard keys


    private :

    std::vector<sf::Keyboard::Key> pkb;           // these are the return values of the two last methods
    std::vector<sf::Mouse::Button> pmb;
};




#endif


