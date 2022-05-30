#ifndef DUNGEONPLUSPLUS_ROOMFACTORY_H
#define DUNGEONPLUSPLUS_ROOMFACTORY_H

#include <memory>
#include "Room.h"

namespace game {

    class RoomFactory {
    public:
        // Entrance repräsentiert das Ende des Enums und muss IMMER am ENDE der Liste stehen
        enum class roomType {Corridor, Cell, Entrance};
        static std::shared_ptr<Room> generateRoom(const roomType &type);
    };

}


#endif //DUNGEONPLUSPLUS_ROOMFACTORY_H
