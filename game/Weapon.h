#ifndef DUNGEONPLUSPLUS_WEAPON_H
#define DUNGEONPLUSPLUS_WEAPON_H

#include "Item.h"

namespace game {

    class Weapon : public Item {
    public:
        Weapon(std::string _name, const int &_damage, const int &_accuracy);
        int getDamageOutput() const;
        int getAccuracy() const;
    private:
        int damageOutput;
        int accuracy;
    };

}

#endif //DUNGEONPLUSPLUS_WEAPON_H
