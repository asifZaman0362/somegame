#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "test");
    sf::CircleShape circle(100.0f, 50U);
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::Red);
        window.draw(circle);
        window.display();
    }
    return EXIT_SUCCESS;
}
