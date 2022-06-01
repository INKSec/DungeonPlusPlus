#include "DungeonMap.h"

void gui::DungeonMap::draw() {
    sf::Texture texture;
    texture.loadFromFile("../images/dark_bg.jpg");
    sf::Sprite bg;
    bg.setTexture(texture);
    bg.setPosition((static_cast<float>(window.getSize().x) * 0.1f), (static_cast<float>(window.getSize().y) * 0.1f));
    bg.setScale((static_cast<float>(window.getSize().x) * 0.8f) / (static_cast<float>(texture.getSize().x)),
                (static_cast<float>(window.getSize().y) * 0.5f) / (static_cast<float>(texture.getSize().y)));
    window.draw(bg);
}

gui::DungeonMap::DungeonMap(sf::RenderWindow &_window, const game::DungeonLayout::roomMap &_dungeonMap) : window{_window}, dungeonMap{_dungeonMap} {}
