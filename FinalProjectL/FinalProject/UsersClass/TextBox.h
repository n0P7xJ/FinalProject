#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

const sf::Font defaultFont = "Font/arial.ttf";
const unsigned int defaultCharacterSize = 50;

class textBox : public sf::RectangleShape{
private:
    sf::Text text;
public:
    TextBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& content, const sf::Font& font = "Font/arial.ttf", unsigned int defaultCharacterSize = 50)
        : sf::RectangleShape(size)
    {
        setFillColor(sf::Color::White);
        setOutlineColor(sf::Color::Black);
        setOutlineThickness(2.f);
        setPosition(position);

        text.setFont(font);
        text.setString(content);
        text.setCharacterSize(characterSize);
        text.setFillColor(sf::Color::Black);

        // Центруємо текст у прямокутнику
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
        text.setPosition(position.x + size.x / 2.f, position.y + size.y / 2.f);
    }

    void setText(const std::string& text){
        if (text.isEmpty()) {
            throw(std::expection("Text box: send empty text"));
        }
        text.setString(content)
    }
};
