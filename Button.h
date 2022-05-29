#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>

namespace gui
{
    class Button {
    public:
        Button() = delete;
        explicit Button(
            const std::string &_text,
            const float &xPos,
            const float &yPos,
            const float &width,
            const float &height,
            const sf::Font &font,
            const std::function<void(void)> &callback
        );
        void render(sf::RenderTarget &target);
        void clicked();
        void setCallback(const std::function<void(void)> &_callback);
        sf::RectangleShape getShape() const;
    private:
        sf::RectangleShape shape;
        sf::Text text;
        sf::Color defaultColor {sf::Color::White};
        std::function<void(void)> callback;
    };
};

#endif // BUTTON_HPP