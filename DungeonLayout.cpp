#include <iostream>
#include "DungeonLayout.h"
#include "RoomFactory.h"

game::DungeonLayout::roomMap game::DungeonLayout::generateDungeon(const unsigned int &roomCount) {
    std::vector<roomPtr> rooms;
    RoomFactory::roomType type;
    rooms.reserve(roomCount);
    // Eingang wird immer als Erstes generieren
    rooms.emplace_back(RoomFactory::generateRoom(RoomFactory::roomType::Entrance));

    for(int i = 1; i < roomCount; i++) {
        type = static_cast<RoomFactory::roomType>(rand() % static_cast<int>(RoomFactory::roomType::Entrance));
        rooms.emplace_back(RoomFactory::generateRoom(type));
    }

    for(const roomPtr &r : rooms) {
        dungeonMap.insert(std::make_pair(currentPosition, r));
        addPossiblePositions();
        getRandomNextPosition();
    }

    currentPosition = startingPosition;

    return dungeonMap;
}

void game::DungeonLayout::addPossiblePositions() {
    unsigned int neighbour;
        if(currentPosition < 90) {
            neighbour = currentPosition + 10;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.emplace_back(neighbour);
            }
        }
        if(currentPosition % 10 != 9) {
            neighbour = currentPosition + 1;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.emplace_back(neighbour);
            }
        }
        if(currentPosition > 20) {
            neighbour = currentPosition - 10;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.emplace_back(neighbour);
            }
        }
        if(currentPosition % 10 != 1) {
            neighbour = currentPosition - 1;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.emplace_back(neighbour);
            }
        }
}


game::DungeonLayout::roomMap game::DungeonLayout::getDungeonMap() const {
    return dungeonMap;
}

void game::DungeonLayout::getRandomNextPosition() {
    currentPosition = roomPositions[rand() % roomPositions.size()];
}

unsigned int game::DungeonLayout::getCurrentPosition() const {
    return currentPosition;
}

void game::DungeonLayout::setCurrentPosition(const unsigned int &newPosition) {
    currentPosition = newPosition;
}

game::DungeonLayout::roomPtr game::DungeonLayout::getCurrentRoom() const {
    return dungeonMap.find(currentPosition)->second;
}
