#include "EnemyFactory.h"

std::shared_ptr<game::Enemy> game::EnemyFactory::generateEnemy(const game::EnemyFactory::enemyType &type) {
    std::shared_ptr<Enemy> enemy;

    switch(type) {
        case enemyType::Spider:
            enemy = std::make_shared<Spider>();
            break;
        case enemyType::Skeleton:
            enemy = std::make_shared<Skeleton>();
            break;
        case enemyType::Boss:
            enemy = std::make_shared<Boss>();
            break;
    }

    return enemy;
}
