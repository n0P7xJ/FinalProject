#include "TextBox.h"

// Text default value
const std::string TextBox::defaultString = "empty";
const unsigned int TextBox::defaultCharacterSize = 12;
const sf::Color TextBox::defaultFillColorText = sf::Color::Black;
const sf::Font TextBox::defaultFontText = [] {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    return font;
}();
// Rectangle default value
const sf::Color TextBox::defaultFillColorBox = sf::Color::White;
const sf::Vector2f TextBox::defaultSize = sf::Vector2f(0.f, 0.f);
// Template default value
const sf::Vector2f TextBox::defaultPosition = sf::Vector2f(0.f, 0.f);


TextBox::TextBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& content, const sf::Color& fillColorBox, const sf::Font& font, const sf::Color& fillColor, const unsigned int& characterSize){
    setRectangleProperties(size, position, fillColorBox);
    setTextProperties(content, font, fillColor, characterSize);
}

void TextBox::setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor){
    sf::RectangleShape::setSize(size);
    sf::RectangleShape::setPosition(position);
    sf::RectangleShape::setFillColor(defaultFillColorBox);
}

void TextBox::setTextProperties(const std::string& content, const sf::Font& font, const sf::Color& fillColor, const unsigned int& characterSize)
{
    sf::Text::setString(content);
    sf::Text::setFont(font);
    sf::Text::setFillColor(fillColor);
    sf::Text::setCharacterSize(characterSize);

    // Центруємо текст у прямокутнику
    sf::FloatRect textBounds = sf::RectangleShape::getLocalBounds();
    sf::RectangleShape::setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    sf::RectangleShape::setPosition(sf::RectangleShape::getPosition().x + sf::RectangleShape::getSize().x / 2.0f, sf::RectangleShape::getPosition().y + sf::RectangleShape::getSize().y / 2.0f);
}
