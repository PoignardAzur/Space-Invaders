
#include "AbstractInputsArray.h"



const std::vector<sf::Mouse::Button>& AbstractInputs::pressedMouseButtons() const          // list of pressed mouse buttons
{
    const_cast<AbstractInputs*>(this)->pmb.clear();

    for (const auto& b : mouseButtons())
    {
        if (b.second)
        const_cast<AbstractInputs*>(this)->pmb.push_back(b.first);
    }

    return pmb;
}


const std::vector<sf::Keyboard::Key>& AbstractInputs::pressedKeyboardButtons() const       // list of pressed keyboard keys
{
    const_cast<AbstractInputs*>(this)->pkb.clear();

    for (const auto& k : keyboardButtons())
    {
        if (k.second)
        const_cast<AbstractInputs*>(this)->pkb.push_back(k.first);
    }

    return pkb;
}



const std::map<sf::Mouse::Button, bool>& AbstractInputs::mouseButtons() const
{
    return const_cast<AbstractInputs*>(this)->_mouseButtons();
}

const std::map<sf::Keyboard::Key , bool>& AbstractInputs::keyboardButtons() const
{
    return const_cast<AbstractInputs*>(this)->_keyboardButtons();
}


std::map<sf::Mouse::Button, bool>& AbstractInputs::mouseButtons()
{
    return _mouseButtons();
}

std::map<sf::Keyboard::Key , bool>& AbstractInputs::keyboardButtons()
{
    return _keyboardButtons();
}


