add_library(game Room.cpp DungeonLayout.cpp RoomFactory.cpp Entity.cpp Enemy.cpp Spider.cpp EnemyFactory.cpp Player.cpp Item.cpp Weapon.cpp Consumable.cpp ItemFactory.cpp)

target_include_directories(game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")