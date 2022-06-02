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
        roomPtr getCurrentRoom() const;
        void setCurrentPosition(const int &newPosition);
    private:
        // Map mit Raum Position als Key und Raum Pointer als Value
        roomMap dungeonMap;
        // Vector mit allen momentan an bestehende Räume angrenzenden, unbebauten Raumplätzen
        std::set<int> roomPositions;
        // Position des Startraumes innerhalb des möglichen Layouts: 11 (unten links) bis 99 (oben rechts)
        const int startingPosition {55};
        int currentPosition {startingPosition};
        void addPossiblePositions();
        void getRandomNextPosition();
    };

}

#endif //DUNGEONPLUSPLUS_DUNGEONLAYOUT_H
