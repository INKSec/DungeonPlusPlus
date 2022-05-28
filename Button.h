#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace gui
{
    class Button {
    public:
        Button() = delete;
        explicit Button(const std::string &_text, const float &xPos, const float &yPos, const float &width, const float &height, const sf::Font &font);
        void render(sf::RenderTarget &target);
        void clicked();
        sf::RectangleShape getShape();
    private:
        sf::RectangleShape shape;
        sf::Text text;
        sf::Color defaultColor {sf::Color::White};
    };
};

#endif // BUTTON_HPP