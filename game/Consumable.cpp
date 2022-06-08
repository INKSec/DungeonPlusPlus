#include "Consumable.h"

#include <utility>

game::Consumable::Consumable(std::string _name, std::function<void(void)> _callback) :
callback{std::move(_callback)} {
    name = std::move(_name);
}
