#include "Button.h"

gui::Button::Button(const std::string &_text, const float &xPos, const float &yPos, const float &width, const float &height, const sf::Font &font) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(xPos, yPos));
    shape.setFillColor(defaultColor);
    text.setFont(font);
    text.setString(_text);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    text.setPosition(
    shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - (text.getGlobalBounds().width / 2.f),
    shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - (text.getGlobalBounds().height / 1.5f)
    );
}

void gui::Button::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(text);
}

sf::RectangleShape gui::Button::getShape() {
    return shape;
}

void gui::Button::clicked() {
    std::cout << "Button clicked!" << std::endl;
}
