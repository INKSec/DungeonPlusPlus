#include "Button.h"

gui::Button::Button(
    const std::string &_text,
    const float &xPos,
    const float &yPos,
    const float &width,
    const float &height,
    const sf::Font &font,
    const std::function<void(void)> &callback
) {
    // Build the and position the button
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(xPos, yPos));
    shape.setFillColor(defaultColor);
    // Build and position the buttonText
    text.setFont(font);
    text.setString(_text);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    text.setPosition(
    shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - (text.getGlobalBounds().width / 2.f),
    shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - (text.getGlobalBounds().height / 1.5f)
    );
    // Bind onClick-functionality to button
    setCallback(callback);
}

// Render/Draw the button in the gameWindow
void gui::Button::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(text);
}

// When clicked, execute the function stored in callback
void gui::Button::clicked() {
    callback();
}

void gui::Button::setCallback(const std::function<void(void)> &_callback) {
    callback = _callback;
}

sf::RectangleShape gui::Button::getShape() const {
    return shape;
}

