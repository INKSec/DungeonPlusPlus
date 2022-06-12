#include "EventWindow.h"

#include <utility>

#define BUTTON_WIDTH 250
#define BUTTON_HEIGHT 50
#define BUTTON_COLOR sf::Color::White
#define BUTTON_TEXT_COLOR sf::Color::Black
#define BUTTON_FONT_SIZE 20
#define MARGIN 20

gui::EventWindow::EventWindow(
    sf::RenderWindow &_window,
    std::string _eventText,
    std::string _button1Text,
    std::function<void(void)> callback1,
    std::string _button2Text,
    std::function<void(void)> callback2)
    :
    window{_window},
    eventText{move(_eventText)},
    button1Text{move(_button1Text)},
    button1Callback{std::move(callback1)},
    button2Text{move(_button2Text)},
    button2Callback{std::move(callback2)}
    {}

void gui::EventWindow::draw() {

    sf::Font font;
    font.loadFromFile("../fonts/Arial.ttf");
    sf::Texture texture;
    texture.loadFromFile("../images/dark_bg.jpg");
    sf::Sprite bg;
    bg.setTexture(texture);
    bg.setPosition((static_cast<float>(window.getSize().x) * 0.285f), (static_cast<float>(window.getSize().y) * 0.25f));
    bg.setScale((static_cast<float>(window.getSize().x) * 0.43f) / (static_cast<float>(texture.getSize().x)),
                (static_cast<float>(window.getSize().y) * 0.25f) / (static_cast<float>(texture.getSize().y)));
    window.draw(bg);
    sf::Text text;
    text.setString(eventText);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(bg.getPosition().x + bg.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2, bg.getPosition().y + 60);
    buttons.emplace_back(
            button1Text,
            bg.getPosition().x + 20,
            bg.getPosition().y + bg.getGlobalBounds().height - MARGIN - BUTTON_HEIGHT,
            BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE,
            BUTTON_COLOR, BUTTON_TEXT_COLOR,
            button1Callback);
    buttons.emplace_back(
            button2Text,
            bg.getPosition().x + 290,
            bg.getPosition().y + bg.getGlobalBounds().height - MARGIN - BUTTON_HEIGHT,
            BUTTON_WIDTH, BUTTON_HEIGHT, font, BUTTON_FONT_SIZE,
            BUTTON_COLOR, BUTTON_TEXT_COLOR,
            button2Callback);
    window.draw(text);
    for(auto &b : buttons) {
        b.render(window);
    }
}

std::vector<gui::Button> gui::EventWindow::getButtons() const {
    return buttons;
}
