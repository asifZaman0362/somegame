#ifndef WINDOW_SETTINGS_HPP
#define WINDOW_SETTINGS_HPP

#include "types.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <string>

struct WindowSettings {
    u32 width = 800;
    u32 height = 480;
    u32 fps_limit = 60;
    bool vsync = true;
    u32 depth = 32;
    u8 style = sf::Style::None;
    std::string title;
};

#endif
