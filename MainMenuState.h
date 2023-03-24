#pragma once

#include <SFML/Graphics.hpp>
#include "states.h"
#include "app.h"

// going to inherit from the state class in "states.h"
class MainMenuState : public States {
public:
    MainMenuState(app_data_ref data);
    void initialize_state();
    void handle_input();
    void update(float delta);
    void draw(float delta);

private:
    app_data_ref _data;
    sf::RectangleShape begin_button;
    sf::RectangleShape cart_button;
    sf::Color base_color;
};