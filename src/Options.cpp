//
// Created by Micha on 10.06.2022.
//

#include "Options.h"

Options::Options(sf::RenderWindow &_window) : window(_window) {
    if(!background.loadFromFile("../images/dark_bg"));
}
