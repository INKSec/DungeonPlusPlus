#ifndef DUNGEONPLUSPLUS_DUNGEONLAYOUT_H
#define DUNGEONPLUSPLUS_DUNGEONLAYOUT_H

#include <map>
#include <memory>
#include "Room.h"

namespace game {

    class DungeonLayout {
    public:
        using roomMap = std::map<unsigned int, std::shared_ptr<Room>>;
        using roomPtr = std::shared_ptr<Room>;
        roomMap generateDungeon(const unsigned int &roomCount);
        roomMap getDungeonMap() const;
        unsigned int getCurrentPosition() const;
        roomPtr getCurrentRoom() const;
        void setCurrentPosition(const unsigned int &newPosition);
    private:
        // Map mit Raum Position als Key und Raum Pointer als Value
        roomMap dungeonMap;
        // Vector mit allen momentan an bestehende Räume angrenzenden, unbebauten Raumplätzen
        std::vector<int> roomPositions;
        // Position des Startraumes innerhalb des möglichen Layouts: 11 (unten links) bis 99 (oben rechts)
        const unsigned int startingPosition {55};
        unsigned int currentPosition {startingPosition};
        void addPossiblePositions();
        void getRandomNextPosition();
    };

}

#endif //DUNGEONPLUSPLUS_DUNGEONLAYOUT_H