#ifndef DUNGEONPLUSPLUS_ROOMFACTORY_H
#define DUNGEONPLUSPLUS_ROOMFACTORY_H

#include <memory>
#include "Room.h"

namespace game {

    class RoomFactory {
    public:
        // Entrance represents the end of the Enum and must remain at the end of the list
        enum class roomType {Corridor, Cell, Entrance};
        static std::shared_ptr<Room> generateRoom(const roomType &type);
    };

}


#endif //DUNGEONPLUSPLUS_ROOMFACTORY_H
