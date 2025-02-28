#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <exception>
#include "settings.h"

class TextBox : public sf::RectangleShape, public sf::Text, public sf::Drawable {
public:
    TextBox(const sf::Vector2f& size = defaultSize, const sf::Vector2f& position = defaultPosition,const std::string& content = defaultString, const sf::Color& fillColorBox = defaultFillColorBox, const sf::Font& font = defaultFontText, const sf::Color& fillColor = defaultFillColorText, unsigned int characterSize = defaultCharacterSize);


    // Метод для задання властивостей прямокутника
    void setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor = defaultFillColorBox);

    // Метод для задання властивостей тексту
    void setTextProperties(const std::string& content, const sf::Font& font, const sf::Color& fillColor,const unsigned int& characterSize);

    //Провірка на нажаття боксу
    bool checkPress(const sf::Vector2f& mousePosition) const;

    //Draw
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
};
