#include "InputManager.h"

bool InputManager::is_button_clicked(sf::RectangleShape button, sf::Mouse::Button mb, sf::RenderWindow &window) {

    if(sf::Mouse::isButtonPressed(mb)) {
        sf::IntRect temp_rect(button.getPosition().x, button.getPosition().y,
                              button.getGlobalBounds().width, button.getGlobalBounds().height);

        if (temp_rect.contains(sf::Mouse::getPosition(window))) {
            return true;
        }
    }

    return false;

}

sf::Vector2i InputManager::get_mouse_pos(sf::RenderWindow &window) {
    return sf::Mouse::getPosition(window);
}