#include "assetmanager.h"

void AssetManager::load_texture(std::string name, std::string file_name) {
    sf::Texture tex;

    // if our texture was successfully loaded
    if (tex.loadFromFile(file_name)) {
        this->textures[name] = tex;
    }
}

sf::Texture &AssetManager::get_texture(std::string name) {
    return this->textures.at(name);
}

void AssetManager::load_font(std::string name, std::string file_name) {
    sf::Font font;

    // if our texture was successfully loaded
    if (font.loadFromFile(file_name)) {
        this->fonts[name] = font;
    }
}

sf::Font &AssetManager::get_font(std::string name) {
    return this->fonts.at(name);
}