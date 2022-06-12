add_library(game Room.cpp DungeonLayout.cpp RoomFactory.cpp Entity.cpp Enemy.cpp enemies/Spider.cpp EnemyFactory.cpp Player.cpp Item.cpp Weapon.cpp Consumable.cpp ItemFactory.cpp enemies/Boss.cpp enemies/Boss.h enemies/Skeleton.cpp enemies/Skeleton.h)

target_include_directories(game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")