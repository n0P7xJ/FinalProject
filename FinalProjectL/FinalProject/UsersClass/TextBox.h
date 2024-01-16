#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <exception>

class TextBox : public sf::RectangleShape, public sf::Text {
    // Text default value
    static const unsigned int defaultCharacterSize;
    static const sf::Color defaultFillColorText;
    static const sf::Font defaultFontText;
    static const std::string defaultString;
    // Rectangle default value
    static const sf::Color defaultFillColorBox;
    static const sf::Vector2f defaultSize;
    // Template defaul value
    static const sf::Vector2f defaultPosition;
public:

    TextBox(const sf::Vector2f& size = defaultSize, const sf::Vector2f& position = defaultPosition, const std::string& content = defaultString, const sf::Color& fillColorBox = defaultFillColorBox, const sf::Font& font = defaultFontText, const sf::Color& fillColor = defaultFillColorText, const unsigned int& characterSize = defaultCharacterSize);

    // Метод для задання властивостей прямокутника
    void setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor = defaultFillColorBox);

    // Метод для задання властивостей тексту
    void setTextProperties(const std::string& content, const sf::Font& font = defaultFontText, const sf::Color& fillColor = defaultFillColorText, const unsigned int& characterSize = defaultCharacterSize);
};
