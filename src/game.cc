#include "game.hpp"

#include <SFML/Window/Event.hpp>

#include "windowsettings.hpp"

Game::Game(const WindowSettings &settings) {
    sf::ContextSettings ctx_settings;
    ctx_settings.depthBits = settings.depth;
    ctx_settings.majorVersion = 3;
    ctx_settings.minorVersion = 3;
    ctx_settings.sRgbCapable = true;
    ctx_settings.antialiasingLevel = 4;
    window.create(sf::VideoMode(settings.width, settings.height),
                  settings.title, settings.style, ctx_settings);
    if (settings.vsync) {
        window.setVerticalSyncEnabled(true);
    } else {
        window.setFramerateLimit(settings.fps_limit);
    }
    is_running = false;
}

void Game::start() {
    is_running = true;
    while (is_running) {
        auto time = clock.restart().asMilliseconds() / 1000.0f;
        process_input();
        update(time);
        draw();
    }
}

void Game::process_input() {
    sf::Event e;
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed: {
                stop();
                break;
            }
            case sf::Event::Resized: {
                resize(e.size.width, e.size.height);
                break;
            }
            default:
                break;
        }
    }
    window.close();
}

void Game::update(float dt) {
}

void Game::resize(u32 width, u32 height) {

}

void Game::pause() {
    //running_state = Paused;
}

void Game::stop() {
    is_running = false;
}
