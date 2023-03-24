#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include <iostream>

MainMenuState::MainMenuState(app_data_ref data) : _data(data) {

}

void MainMenuState::initialize_state() {
    // Load textures and setup button positions, colors, etc
    this->begin_button.setSize(sf::Vector2f(150, 120));
    this->begin_button.setOrigin((this->begin_button.getSize().x/2), this->begin_button.getSize().y/2);
    this->begin_button.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

    this->cart_button.setSize(sf::Vector2f(60,60));
    this->cart_button.setOrigin((this->cart_button.getSize().x/2), this->cart_button.getSize().y/2);
    this->cart_button.setPosition((this->_data->window.getSize().x/3), (this->_data->window.getSize().y/3));
}

void MainMenuState::handle_input() {
    sf::Event event;
    while(this->_data->window.pollEvent(event)) {
        // switch statement to cycle through the different events on the window
        switch (event.type) {
            // if the event is the user pressing the close button
            case sf::Event::Closed:
                this->_data->window.close();
                break;

                // if the mouse is moved onto the start button
            case sf::Event::MouseMoved: {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(this->_data->window);
                sf::Vector2f mouse_pos_f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

                if (this->begin_button.getGlobalBounds().contains(mouse_pos_f)) {
                    this->begin_button.setFillColor(sf::Color(100, 10, 10));
                } else {
                    this->begin_button.setFillColor(this->base_color);
                }
            }
                break;

                // if the mouse is clicked while over the start button
            case sf::Event::MouseButtonPressed: {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(this->_data->window);
                sf::Vector2f mouse_pos_f(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));

                // if the mouse is clicked it'll run the view options function
                if (this->begin_button.getGlobalBounds().contains(mouse_pos_f)) {
                    std::cout << "Options" << std::endl;
                } else {
                    this->begin_button.setFillColor(this->base_color);
                }
            }
                break;
        }
    }
}

void MainMenuState::update(float delta) {
    // Switch to the options list
    std::cout << "Go To Drinks/Sides/Mains" << std::endl;
}

void MainMenuState::draw(float delta) {
    this->_data->window.clear(sf::Color::White);
    this->_data->window.draw(this->begin_button);
    this->_data->window.draw(this->cart_button);

    this->_data->window.display();
}