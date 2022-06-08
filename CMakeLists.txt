cmake_minimum_required(VERSION 3.21)
project(DungeonPlusPlus)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(game src)
add_executable(DungeonPlusPlus src/main.cpp src/MainMenu.cpp src/GameScene.cpp src/Button.cpp src/DungeonMap.cpp src/Inventory.cpp)
include_directories(headers /usr/include D:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
        include_directories(SFML_INCLUDE_DIR)
        target_link_libraries(DungeonPlusPlus PUBLIC ${SFML_LIBRARIES} game)
endif()
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


