#ifndef DUNGEONPLUSPLUS_ENEMYFACTORY_H
#define DUNGEONPLUSPLUS_ENEMYFACTORY_H

#include <memory>
#include "enemies/Spider.h"
#include "enemies/Boss.h"
#include "enemies/Skeleton.h"

namespace game {

    class EnemyFactory {
    public:
        // Boss represents the end of the Enum and must remain at the end of the list
        enum class enemyType {Spider, Skeleton, Boss};
        static std::shared_ptr<Enemy> generateEnemy(const enemyType &type);
    };

}

#endif //DUNGEONPLUSPLUS_ENEMYFACTORY_H
