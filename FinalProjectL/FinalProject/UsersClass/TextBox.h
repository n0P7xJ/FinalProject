#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

class TextBox : public sf::RectangleShape, public sf::Text {
public:
    TextBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& content, const sf::Font& font = defaultFontText, const sf::Color& fillColor = defaultFillColorText, unsigned int characterSize = defaultCharacterSize);

    // Метод для задання властивостей прямокутника
    void setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position);

    // Метод для задання властивостей тексту
    void setTextProperties(const std::string& content, const sf::Font& font, const sf::Color& fillColor = defaultFillColorText, unsigned int characterSize);
private:
    // Text default value
    static const unsigned int defaultCharacterSize;
    static const sf::Color defaultFillColorText;
    static const sf::Font defaultFontText;
};
