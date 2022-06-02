#include "GameScene.h"
#include <iostream>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_COLOR sf::Color::White
#define BUTTON_TEXT_COLOR sf::Color::Black
#define BUTTON_FONT_SIZE 20

gui::GameScene::GameScene(
    sf::RenderWindow &_window,
    game::DungeonLayout &_dungeonLayout,
    gui::DungeonMap &_dungeonMap)
    :
    window{_window},
    dungeonLayout(_dungeonLayout),
    dungeonMap{_dungeonMap}
{
    font.loadFromFile("../fonts/Arial.ttf");
    setHUD("../images/hud.jpg");
}

// Draw all graphical elements in the scene and display them
void gui::GameScene::display(const std::shared_ptr<game::Room> &currentRoom) {
    sf::Sprite _hud;
    _hud.setTexture(hud);
    _hud.setPosition(0, static_cast<float>(window.getSize().y) - _hud.getGlobalBounds().height);
    sf::Sprite bg;
    setBackground(currentRoom->getBackground());
    bg.setTexture(background);
    bg.setScale(static_cast<float>(window.getSize().x) / static_cast<float>(background.getSize().x),
                (static_cast<float>(window.getSize().y) - _hud.getGlobalBounds().height) / static_cast<float>(background.getSize().y));
    window.clear();
    window.draw(bg);
    window.draw(_hud);
    explorationView();
    if(mapIsOpen) dungeonMap.draw();
    window.display();
}

// Generate the specific HUD elements for the Dungeon Exploration state
void gui::GameScene::explorationView() {
    const unsigned int Row1 {window.getSize().y - 200};
    const unsigned int Row2 {window.getSize().y - 100};
    const unsigned int Col1 {50};
    const unsigned int Col2 {300};
    const unsigned int Col3 {550};
    std::cout << "Current Position: " << dungeonLayout.getCurrentPosition() << std::endl;
    buttons.emplace_back("Go North", Col1, Row1, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        const int newPosition = {dungeonLayout.getCurrentPosition() + 10};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further north." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go East", Col2, Row1, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        const int newPosition = {dungeonLayout.getCurrentPosition() + 1};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further east." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go West", Col1, Row2, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        const int newPosition = {dungeonLayout.getCurrentPosition() - 1};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further west." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go South", Col2, Row2, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        const int newPosition = {dungeonLayout.getCurrentPosition() - 10};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further south." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Map", Col3, Row1, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        mapIsOpen = !mapIsOpen;
        display(dungeonLayout.getCurrentRoom());
    });
    for(auto &b : buttons) {
        b.render(window);
    }
}

// Generate the specific HUD elements for the Combat state
void gui::GameScene::combatView() {}

void gui::GameScene::setBackground(const std::string &path) {
    background.loadFromFile(path);
}

void gui::GameScene::setHUD(const std::string &path) {
    hud.loadFromFile(path);
}

std::vector<gui::Button> gui::GameScene::getButtons() const {
    return buttons;
}