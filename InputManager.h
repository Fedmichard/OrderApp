#pragma once

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() {};
    ~InputManager() {};

    bool is_button_clicked(sf::RectangleShape button, sf::Mouse::Button mb, sf::RenderWindow &window);

    sf::Vector2i get_mouse_pos(sf::RenderWindow &window);

};