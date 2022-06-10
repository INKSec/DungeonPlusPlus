#ifndef DUNGEONPLUSPLUS_PLAYER_H
#define DUNGEONPLUSPLUS_PLAYER_H

#include "Entity.h"
#include "Weapon.h"
namespace game {

    class Player : public Entity {
    public:
        explicit Player();
        void equipWeapon(const std::shared_ptr<Weapon> &_weapon);
        std::shared_ptr<Weapon> getEquippedWeapon() const;
    private:
        std::shared_ptr<Weapon> weapon;
    };

}

#endif //DUNGEONPLUSPLUS_PLAYER_H




