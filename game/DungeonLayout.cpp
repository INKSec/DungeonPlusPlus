#include <iostream>
#include <vector>
#include <ctime>
#include "DungeonLayout.h"
#include "RoomFactory.h"
#include "EnemyFactory.h"

game::DungeonLayout::roomMap game::DungeonLayout::generateDungeon(const int &roomCount) {
    std::vector<roomPtr> rooms;
    RoomFactory::roomType rType;
    EnemyFactory::enemyType eType;
    rooms.reserve(roomCount);
    // Always generate the Entrance-Room first
    rooms.emplace_back(RoomFactory::generateRoom(RoomFactory::roomType::Entrance));

    // Randomly generate Rooms of different Types (other than Entrance)
    srand(time(nullptr));
    for(int i = 1; i < roomCount; i++) {
        rType = static_cast<RoomFactory::roomType>(rand() % static_cast<int>(RoomFactory::roomType::Entrance));
        rooms.emplace_back(RoomFactory::generateRoom(rType));
        if(rand() % 2) {
            eType = static_cast<EnemyFactory::enemyType>(rand() % static_cast<int>(EnemyFactory::enemyType::Boss));
            rooms[i]->setEnemy(EnemyFactory::generateEnemy(eType));
        }
    }

    // Generate the Bossroom
    rooms.emplace_back(RoomFactory::generateRoom(RoomFactory::roomType::Bossroom));
    rooms.back()->setEnemy(EnemyFactory::generateEnemy(EnemyFactory::enemyType::Boss));

    // Place the rooms in the map with a randomly selected Position that connects to at least 1 other Room
    for(const roomPtr &r : rooms) {
        dungeonMap.insert(std::make_pair(currentPosition, r));
        addPossiblePositions();
        getRandomNextPosition();
    }

    currentPosition = startingPosition;

    return dungeonMap;
}

// Calculate possible Positions where the next Room can be placed at
void game::DungeonLayout::addPossiblePositions() {
    int neighbour;
        if(currentPosition < 80) {
            neighbour = currentPosition + 10;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.insert(neighbour);
            }
        }
        if(currentPosition % 10 != 9) {
            neighbour = currentPosition + 1;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.insert(neighbour);
            }
        }
        if(currentPosition > 30) {
            neighbour = currentPosition - 10;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.insert(neighbour);
            }
        }
        if(currentPosition % 10 != 1) {
            neighbour = currentPosition - 1;
            if(!dungeonMap.count(neighbour)) {
                roomPositions.insert(neighbour);
            }
        }
        roomPositions.erase(currentPosition);
}

// Randomly select one of the currently possible Locations
void game::DungeonLayout::getRandomNextPosition() {
    auto it {roomPositions.begin()};
    unsigned long long random {rand() % roomPositions.size()};
    std::advance(it, random);
    currentPosition = *it;
}

game::DungeonLayout::roomMap game::DungeonLayout::getDungeonMap() const {
    return dungeonMap;
}

int game::DungeonLayout::getCurrentPosition() const {
    return currentPosition;
}

int game::DungeonLayout::getPreviousPosition() const {
    return previousPosition;
}

void game::DungeonLayout::setCurrentPosition(const int &newPosition) {
    if(newPosition != currentPosition) {
        previousPosition = currentPosition;
        currentPosition = newPosition;
    }
}

game::DungeonLayout::roomPtr game::DungeonLayout::getCurrentRoom() const {
    return dungeonMap.find(currentPosition)->second;
}