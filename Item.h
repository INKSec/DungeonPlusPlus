#ifndef DUNGEONPLUSPLUS_ITEM_H
#define DUNGEONPLUSPLUS_ITEM_H

#include <string>

namespace game {

    class Item {
    public:
        virtual ~Item() = default;
        virtual std::string getName() const;
    protected:
        Item() = default;
        std::string name;
    };

}

#endif //DUNGEONPLUSPLUS_ITEM_H
