#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "statemachine.h"
#include "assetmanager.h"
#include "InputManager.h"

struct AppData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

typedef std::shared_ptr<AppData> app_data_ref;

class app {
public:
    app(int width, int height, std::string title);
    ~app();

private:
    // our frame rate, clock required for handling framerate
    const float delta = 1.0f/60.0f;
    const sf::Time time_per_frame = sf::seconds(1.0f/60.0f);
    sf::Clock clock;

    app_data_ref _data = std::make_shared<AppData>();

    // will run when we start our app
    void run();
};