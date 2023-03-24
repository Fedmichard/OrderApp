cmake_minimum_required(VERSION 3.23)
project(classproject)

set(CMAKE_CXX_STANDARD 17)

add_executable(classproject main.cpp statemachine.h states.h statemachine.cpp assetmanager.h assetmanager.cpp App.cpp app.h DEFINITIONS.h MainMenuState.h MainMenuState.cpp InputManager.h InputManager.cpp OptionsState.h OptionsState.cpp CheckoutState.h CheckoutState.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(classproject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)