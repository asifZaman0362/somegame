#ifndef GAME_HPP
#define GAME_HPP

#include "types.hpp"
#include "windowsettings.hpp"
#include "scene.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
 public:
    /*enum GameRunningState {
        Running, Stopped, Paused
    };*/
 private:
    static sf::RenderWindow window;
    bool is_running;
    sf::Clock clock;
 public:
    Game(const WindowSettings&);
    ~Game() = default;

    void start();
    void process_input();
    void update(float);
    void resize(u32, u32);
    void draw();
    void pause();
    void stop();
    // temporary
    static sf::RenderTarget& get_window_surface();
};

#endif
