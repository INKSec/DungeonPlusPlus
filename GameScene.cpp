#include "GameScene.h"
#include <iostream>

game::GameScene::GameScene(DungeonLayout &_dungeonLayout) : dungeonLayout(_dungeonLayout) {
    font.loadFromFile("../fonts/Arial.ttf");
    setHUD("../images/hud.jpg");
}

// Diese Funktion setzt alle grafischen Elemente einer Spielszene zusammen und stellt sie dar
void game::GameScene::display(sf::RenderWindow &window, const std::shared_ptr<Room> &currentRoom) {
    sf::Sprite _hud;
    _hud.setTexture(hud);
    _hud.setPosition(0, window.getSize().y - _hud.getGlobalBounds().height);
    sf::Sprite bg;
    setBackground(currentRoom->getBackground());
    bg.setTexture(background);
    bg.setScale(window.getSize().x / static_cast<float>(background.getSize().x),
                (window.getSize().y - _hud.getGlobalBounds().height) / static_cast<float>(background.getSize().y));
    window.clear();
    window.draw(bg);
    window.draw(_hud);
    explorationView(window);
    window.display();
}

void game::GameScene::explorationView(sf::RenderWindow &window) {
    const unsigned int Row1 {window.getSize().y - 200};
    const unsigned int Row2 {window.getSize().y - 100};
    const unsigned int Col1 {50};
    const unsigned int Col2 {300};
    std::cout << "Current Position: " << dungeonLayout.getCurrentPosition() << std::endl;
    buttons.emplace_back("Go North", Col1, Row1, 200, 50, font, [&](){
        const unsigned int newPosition = {dungeonLayout.getCurrentPosition() + 10};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(window, dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further north." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go East", Col2, Row1, 200, 50, font, [&](){
        const unsigned int newPosition = {dungeonLayout.getCurrentPosition() + 1};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(window, dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further east." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go West", Col1, Row2, 200, 50, font, [&](){
        const unsigned int newPosition = {dungeonLayout.getCurrentPosition() - 1};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(window, dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further west." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    buttons.emplace_back("Go South", Col2, Row2, 200, 50, font, [&](){
        const unsigned int newPosition = {dungeonLayout.getCurrentPosition() - 10};
        if(dungeonLayout.getDungeonMap().count(newPosition)) {
            dungeonLayout.setCurrentPosition(newPosition);
            display(window, dungeonLayout.getCurrentRoom());
        } else {
            std::cerr << "Couldn't move further south." << dungeonLayout.getCurrentPosition() << std::endl;
        }
    });
    for(auto &b : buttons) {
        b.render(window);
    }
}

void game::GameScene::combatView() {}

void game::GameScene::setBackground(const std::string &path) {
    background.loadFromFile(path);
}

void game::GameScene::setHUD(const std::string &path) {
    hud.loadFromFile(path);
}

std::vector<gui::Button> game::GameScene::getButtons() const {
    return buttons;
}
