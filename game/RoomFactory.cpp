#include "RoomFactory.h"

std::shared_ptr<game::Room> game::RoomFactory::generateRoom(const game::RoomFactory::roomType &type) {
    std::shared_ptr<Room> room;

    switch(type) {
        case roomType::Entrance:
            room = std::make_shared<Room>("../images/entrance.png", "Entrance");
            break;
        case roomType::Corridor:
            room = std::make_shared<Room>("../images/corridor.png", "Corridor");
            break;
        case roomType::Lib:
            room = std::make_shared<Room>("../images/lib.png", "Library");
            break;
        case roomType::Cell:
            room = std::make_shared<Room>("../images/cell.png", "Cell");
            break;
        case roomType::Bossroom:
            room = std::make_shared<Room>("../images/bossroom.png", "Boss");
            break;

    }

    return room;
}
