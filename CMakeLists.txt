cmake_minimum_required(VERSION 3.21)
project(DungeonPlusPlus)

set(CMAKE_CXX_STANDARD 14)
add_executable(DungeonPlusPlus main.cpp MainMenu.cpp MainMenu.h GameScene.cpp GameScene.h Button.cpp Button.h Room.cpp Room.h DungeonLayout.cpp DungeonLayout.h RoomFactory.cpp RoomFactory.h)
include_directories(headers /usr/include D:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
        include_directories(SFML_INCLUDE_DIR)
        target_link_libraries(DungeonPlusPlus ${SFML_LIBRARIES})
endif()
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


