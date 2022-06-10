

#ifndef DUNGEONPLUSPLUS_OPTIONS_H
#define DUNGEONPLUSPLUS_OPTIONS_H



#include <SFML\Graphics.hpp>


class Options {
public:
    Options() = delete;
    Options(sf::RenderWindow &_window);
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Sprite backgroundImage;

};


#endif //DUNGEONPLUSPLUS_OPTIONS_H
