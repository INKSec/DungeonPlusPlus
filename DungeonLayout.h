#ifndef DUNGEONPLUSPLUS_DUNGEONLAYOUT_H
#define DUNGEONPLUSPLUS_DUNGEONLAYOUT_H

#include <map>
#include <memory>
#include <set>
#include "Room.h"

namespace game {

    class DungeonLayout {
    public:
        using roomPtr = std::shared_ptr<Room>;
        using roomMap = std::map<int, roomPtr>;
        roomMap generateDungeon(const int &roomCount);
        roomMap getDungeonMap() const;
        int getCurrentPosition() const;
        int getPreviousPosition() const;
        roomPtr getCurrentRoom() const;
        void setCurrentPosition(const int &newPosition);
    private:
        /*
         * Map of Rooms.
         * Key: int value representing the room's position
         * Value: shared_ptr to the actual Room Object
        */
        roomMap dungeonMap;
        // Set that holds possible empty positions where a room can still be placed
        std::set<int> roomPositions;
        // Position of Dungeon Entrance (first Room). Dungeon ranges from 11 (bottom left) to 99 (top right)
        const int startingPosition {55};
        int currentPosition {startingPosition};
        int previousPosition {startingPosition};
        void addPossiblePositions();
        void getRandomNextPosition();
    };

}

#endif //DUNGEONPLUSPLUS_DUNGEONLAYOUT_H
