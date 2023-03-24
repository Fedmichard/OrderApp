#include "app.h"
#include "MainMenuState.h"

app::app(int width, int height, std::string title) {
    _data->window.create(sf::VideoMode(width, height),
                         "Begin Order Menu", sf::Style::Close | sf::Style::Titlebar);
    // Need to implement a state, the first state
    _data->machine.add_state(state_reference(new MainMenuState(this->_data)));
    this->run();
}


app::~app() {

}

void app::run() {

    float new_time, frame_time, interpolation;

    float current_time = this->clock.getElapsedTime().asSeconds();
    sf::Time time_since_last_frame = sf::Time::Zero;
    // float accumulator = 0.0f;

    while (this->_data->window.isOpen()) {
        // first thing you want to do in our loop is look for any state changes
        time_since_last_frame += clock.restart();

        while (time_since_last_frame > time_per_frame) {
            this->_data->machine.process_state_changes();
            this->_data->machine.get_active_state()->handle_input();
            this->_data->machine.get_active_state()->update(delta);
            this->_data->machine.get_active_state()->draw(delta);

        }



        /*
        new_time = this->clock.getElapsedTime().asSeconds();
        frame_time = new_time - current_time;

        if (frame_time > 0.25f) {
            frame_time = 0.25f;
        }

        current_time = new_time;
        accumulator += frame_time;

        while (accumulator >= delta) {
            this->_data->machine.get_active_state()->handle_input();
            this->_data->machine.get_active_state()->update(delta);

            accumulator -= delta;
        }

        interpolation = accumulator/delta;
        this->_data->machine.get_active_state()->draw(interpolation);
         */

    }

}

