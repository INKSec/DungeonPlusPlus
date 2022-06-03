#include "Room.h"
#include <utility>

game::Room::Room(std::string pathToBackground, std::string _name) : name{std::move(_name)}, background{std::move(pathToBackground)} {}

std::string game::Room::getBackground() const {
    return background;
}

std::string game::Room::getName() const {
    return name;
}

void game::Room::setEnemy(std::shared_ptr<Enemy> _enemy) {
    enemy = std::move(_enemy);
}

std::shared_ptr<game::Enemy> game::Room::getEnemy() const {
    return enemy;
}
