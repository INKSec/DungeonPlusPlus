#ifndef DUNGEONPLUSPLUS_ITEMFACTORY_H
#define DUNGEONPLUSPLUS_ITEMFACTORY_H

#include <memory>
#include "Weapon.h"
#include "Consumable.h"

namespace game {

    class ItemFactory {
    public:
        enum class weaponType {Sword, Axe, Warhammer, Dagger, AK47};
        enum class consumableType {Potion, End};
        static std::shared_ptr<Weapon> generateWeapon(const weaponType &type);
        static std::shared_ptr<Consumable> generateConsumable(const consumableType &type);
    };

}

#endif //DUNGEONPLUSPLUS_ITEMFACTORY_H
// Eventfactory
// Kampf aufbessern
// optionen