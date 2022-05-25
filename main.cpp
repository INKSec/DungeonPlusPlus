#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640,480), "DungeonPlusPlus");
    sf::CircleShape circle(65, 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch ( (event.type)) {
                case sf::Event::Closed:
                    window.close();
                    break;

            }
        }
        window.clear();
        window.draw(circle);
        window.display();
    }



    return 0;
}
