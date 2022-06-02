#include "DungeonMap.h"

#define BUTTON_WIDTH 50
#define BUTTON_HEIGHT 50
#define BUTTON_COLOR sf::Color::White
#define BUTTON_TEXT_COLOR sf::Color::Black

void gui::DungeonMap::draw() {
    sf::Font font;
    font.loadFromFile("../fonts/Arial.ttf");
    sf::Texture texture;
    texture.loadFromFile("../images/dark_bg.jpg");
    sf::Sprite bg;
    bg.setTexture(texture);
    bg.setPosition((static_cast<float>(window.getSize().x) * 0.1f), (static_cast<float>(window.getSize().y) * 0.1f));
    bg.setScale((static_cast<float>(window.getSize().x) * 0.8f) / (static_cast<float>(texture.getSize().x)),
                (static_cast<float>(window.getSize().y) * 0.5f) / (static_cast<float>(texture.getSize().y)));
    window.draw(bg);
    mapCenterX = bg.getPosition().x + (bg.getGlobalBounds().width / 2);
    mapCenterY = bg.getPosition().y + (bg.getGlobalBounds().height / 2);
    for(auto &r : dungeonMap) {
        Button roomButton{
            "",
            calcPosition<Axis::xAxis>(r.first) - BUTTON_WIDTH / 2,
            calcPosition<Axis::yAxis>(r.first) - BUTTON_HEIGHT / 2,
            BUTTON_WIDTH, BUTTON_HEIGHT, font,
            BUTTON_COLOR, BUTTON_TEXT_COLOR,
            [](){
            std::cout << "Clicked!" << std::endl;
            }
        };
        roomButton.render(window);
    }
}

gui::DungeonMap::DungeonMap(sf::RenderWindow &_window, const game::DungeonLayout::roomMap &_dungeonMap) : window{_window}, dungeonMap{_dungeonMap} {}

template<gui::DungeonMap::Axis axis>
float gui::DungeonMap::calcPosition(const int &relativePosition) const {
    float newPosition;
    switch(axis) {
        case Axis::xAxis:
            newPosition = static_cast<float>((relativePosition % 10) - 5);
            newPosition = mapCenterX + (newPosition * 80);
            break;
        case Axis::yAxis:
            newPosition = mapCenterY + static_cast<float>(((relativePosition / 10) - 5) * 80);
            break;
    }
    return newPosition;
}
