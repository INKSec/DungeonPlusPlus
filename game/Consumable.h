#ifndef DUNGEONPLUSPLUS_CONSUMABLE_H
#define DUNGEONPLUSPLUS_CONSUMABLE_H

#include <functional>
#include "Item.h"

namespace game {

    class Consumable : public Item {
    public:
        Consumable(std::string _name, std::function<void(void)> _callback);
    private:
        std::function<void(void)> callback;
    };

}

#endif //DUNGEONPLUSPLUS_CONSUMABLE_H
