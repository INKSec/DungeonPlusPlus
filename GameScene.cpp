#include "GameScene.h"
#include <iostream>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_COLOR sf::Color::White
#define BUTTON_TEXT_COLOR sf::Color::Black
#define BUTTON_FONT_SIZE 20
#define ROW1 window.getSize().y - 180

gui::GameScene::GameScene(
    sf::RenderWindow &_window,
    std::shared_ptr<game::Player> &_player,
    game::DungeonLayout &_dungeonLayout,
    gui::DungeonMap &_dungeonMap)
    :
    window{_window},
    player{_player},
    dungeonLayout(_dungeonLayout),
    dungeonMap{_dungeonMap}
{
    font.loadFromFile("../fonts/Arial.ttf");
    setHUD("../images/hud.jpg");
}

// Draw all graphical elements in the scene and display them
void gui::GameScene::display(const std::shared_ptr<game::Room> &currentRoom) {
    sf::Sprite _hud;
    _hud.setScale(1, 0.9);
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
    drawPlayer();
    drawHealthBar();
    buttons.clear();
    if(currentRoom->getEnemy() != nullptr && currentRoom->getEnemy()->getCurrentHealth() > 0) {
        combatView();
    } else {
        explorationView();
    }
    if(mapIsOpen) dungeonMap.draw(dungeonLayout.getCurrentPosition());
    window.display();
}

// Generate the specific HUD elements for the Dungeon Exploration state
void gui::GameScene::explorationView() {
    const unsigned int Row1 {window.getSize().y - 180};
    const unsigned int Row2 {window.getSize().y - 90};
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
    buttons.emplace_back(
            "Map", Col3, Row1,
            BUTTON_WIDTH, BUTTON_HEIGHT,
            font, BUTTON_FONT_SIZE,
            (mapIsOpen ? BUTTON_TEXT_COLOR : BUTTON_COLOR),
            (mapIsOpen ? BUTTON_COLOR : BUTTON_TEXT_COLOR),
            [this](){
        mapIsOpen = !mapIsOpen;
        display(dungeonLayout.getCurrentRoom());
    });
    for(auto &b : buttons) {
        b.render(window);
    }
}

// Generate the specific HUD elements for the Combat state
void gui::GameScene::combatView() {
    const unsigned int Row1 {window.getSize().y - 180};
    const unsigned int Row2 {window.getSize().y - 90};
    const unsigned int Col1 {50};
    const unsigned int Col2 {300};
    const unsigned int Col3 {550};
    mapIsOpen = false;
    std::cout << "Current Position: " << dungeonLayout.getCurrentPosition() << std::endl;
    buttons.emplace_back("Attack", Col1, Row1, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        player->attack(dungeonLayout.getCurrentRoom()->getEnemy());
        dungeonLayout.getCurrentRoom()->getEnemy()->attack(player);
        display(dungeonLayout.getCurrentRoom());
    });
    buttons.emplace_back("Retreat", Col2, Row1, BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE, BUTTON_COLOR, BUTTON_TEXT_COLOR, [this](){
        dungeonLayout.setCurrentPosition(dungeonLayout.getPreviousPosition());
        display(dungeonLayout.getCurrentRoom());
    });
    for(auto &b : buttons) {
        b.render(window);
    }
    drawEnemy();
}

void gui::GameScene::drawEnemy() {
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile(dungeonLayout.getCurrentRoom()->getEnemy()->getSprite());
    sprite.setTexture(texture);
    sprite.setPosition(window.getSize().x * 0.5f, window.getSize().y * 0.45f);
    window.draw(sprite);
}

void gui::GameScene::drawPlayer() {
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile(player->getSprite());
    sprite.setTexture(texture);
    sprite.setPosition(window.getSize().x * 0.1f, window.getSize().y * 0.2f);
    window.draw(sprite);
}

void gui::GameScene::drawHealthBar() {
    sf::RectangleShape health, bar;
    sf::Text text;
    bar.setSize(sf::Vector2f{300, 50});
    bar.setPosition(window.getSize().x - 350, ROW1);
    bar.setFillColor(sf::Color::Black);
    health.setSize(sf::Vector2f{290.f * (static_cast<float>(player->getCurrentHealth()) / (static_cast<float>(player->getMaxHealth()))), 40});
    health.setPosition(bar.getPosition().x + 5, bar.getPosition().y + 5);
    health.setFillColor(sf::Color::Red);
    text.setFont(font);
    text.setString(std::to_string(player->getCurrentHealth()) + "/" + std::to_string(player->getMaxHealth()));
    text.setCharacterSize(16);
    text.setPosition(bar.getPosition().x + bar.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2, bar.getPosition().y + bar.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5f);
    text.setFillColor(sf::Color::White);
    window.draw(bar);
    window.draw(health);
    window.draw(text);
}


void gui::GameScene::setBackground(const std::string &path) {
    background.loadFromFile(path);
}

void gui::GameScene::setHUD(const std::string &path) {
    hud.loadFromFile(path);
}

std::vector<gui::Button> gui::GameScene::getButtons() const {
    return buttons;
}