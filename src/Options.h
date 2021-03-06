

#ifndef DUNGEONPLUSPLUS_OPTIONS_H
#define DUNGEONPLUSPLUS_OPTIONS_H


#include <iostream>
#include <SFML\Graphics.hpp>
#include "Button.h"
#include "MainMenu.h"

namespace Optionen {
    class Options {
    public:
        Options() = delete;
        explicit Options(sf::RenderWindow &_window);
        ~Options() = default;
        void draw(int&, int&);
        std::vector<gui::Button> getButtons() const;

    private:
        sf::RenderWindow &window;
        sf::Texture background;
        sf::Sprite backgroundImage;
        sf::Font font;
        std::vector<gui::Button> buttons;

    };
}

#endif //DUNGEONPLUSPLUS_OPTIONS_H
