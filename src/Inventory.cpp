#include "Inventory.h"

#define BUTTON_WIDTH 245
#define BUTTON_HEIGHT 40
#define BUTTON_COLOR sf::Color::White
#define EQUIPPED_COLOR sf::Color::Green
#define BUTTON_TEXT_COLOR sf::Color::Black
#define BUTTON_FONT_SIZE 18
#define INVENTORY_CAPACITY 8

gui::Inventory::Inventory(sf::RenderWindow &_window) : window{_window} {}

void gui::Inventory::draw() {
    sf::Font font;
    font.loadFromFile("../fonts/Arial.ttf");
    sf::Texture texture;
    texture.loadFromFile("../images/dark_bg.jpg");
    sf::Sprite bg;
    bg.setTexture(texture);
    bg.setPosition((static_cast<float>(window.getSize().x) * 0.38f), (static_cast<float>(window.getSize().y) * 0.025f));
    bg.setScale((static_cast<float>(window.getSize().x) * 0.24f) / (static_cast<float>(texture.getSize().x)),
                (static_cast<float>(window.getSize().y) * 0.65f) / (static_cast<float>(texture.getSize().y)));
    window.draw(bg);
    int offset {0};
    itemButtons.clear();
    for(const auto &i : items) {
        itemButtons.emplace_back(
                i->getName(),
                bg.getPosition().x + 20,
                bg.getPosition().y + 20 + offset,
                BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE,
                BUTTON_COLOR, BUTTON_TEXT_COLOR,
                [this](){
                    std::cout << "Clicked!" << std::endl;
                    //drawContextMenu();
                });
        offset += 62;
    }
    for(auto &i : itemButtons) {
        i.render(window);
    }
}

void gui::Inventory::drawContextMenu(const gui::Button &_button) {

}

void gui::Inventory::putItem(const std::shared_ptr<game::Item> &_item) {
    if(items.size() < INVENTORY_CAPACITY) {
        items.emplace_back(_item);
    } else {
        std::cout << "Inventory full!" << std::endl;
    }
}

std::vector<std::shared_ptr<game::Item>> gui::Inventory::getItems() const {
    return items;
}

std::vector<gui::Button> gui::Inventory::getButtons() const {
    return itemButtons;
}