#include "Weapon.h"

#include <utility>

game::Weapon::Weapon(std::string _name, const int &_damage, const int &_accuracy) :
damageOutput{_damage}, accuracy{_accuracy} {
    name = std::move(_name);
    itemType = ItemType::Weapon;
}

int game::Weapon::getDamageOutput() const {
    return damageOutput;
}

int game::Weapon::getAccuracy() const {
    return accuracy;
}

// Overload + operator to add two Box objects.
game::Weapon game::Weapon::operator+(const game::Weapon &w) {
    return {this->name + "+" + w.name, this->damageOutput+w.damageOutput, this->accuracy};
}