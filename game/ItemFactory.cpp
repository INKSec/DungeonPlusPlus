#include <iostream>
#include "ItemFactory.h"

std::shared_ptr<game::Weapon> game::ItemFactory::generateWeapon(const game::ItemFactory::weaponType &type) {
    std::shared_ptr<Weapon> weapon;

    switch(type) {
        case weaponType::Sword:
            weapon = std::make_shared<Weapon>("Sword", 6, 95);
            break;
        case weaponType::Axe:
            weapon = std::make_shared<Weapon>("Axe", 8, 80);
            break;
        case weaponType::Warhammer:
            weapon = std::make_shared<Weapon>("Warhammer", 10, 60);
            break;
        case weaponType::Dagger:
            weapon = std::make_shared<Weapon>("Dagger", 4, 85);
            break;
    }

    return weapon;
}

std::shared_ptr<game::Consumable> game::ItemFactory::generateConsumable(const game::ItemFactory::consumableType &type) {
    std::shared_ptr<Consumable> consumable;

    switch(type) {
        case consumableType::Potion:
            consumable = std::make_shared<Consumable>("Potion", [](){
                std::cout << "Potion consumed" << std::endl;
            });
            break;
        case consumableType::End:
            break;
    }

    return consumable;
}
