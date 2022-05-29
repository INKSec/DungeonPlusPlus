#include "Room.h"

#include <utility>

std::string game::Room::getBackground() const {
    return background;
}

std::string game::Room::getName() const {
    return name;
}

game::Room::Room(std::string pathToBackground, std::string _name) : name{std::move(_name)}, background{std::move(pathToBackground)} {}
