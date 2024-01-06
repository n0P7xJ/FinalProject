#include "TextBox.h"

//Text Default Value
static const unsigned int defaultCharacterSize = 12;
const sf::Color TextBox::defaultFillColorText = sf::Color::Black;
const sf::Font TextBox::defaultFontText = [] {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    return font;
}();
//Rectangle Default Value
static const sf::Color defaultFillColorBox = sf::Color::White;

TextBox::TextBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& content, const sf::Color& fillColorBox, const sf::Font& font, const sf::Color& fillColor, unsigned int characterSize) {
    setRectangleProperties(size, position, fillColorBox);
    setTextProperties(content, font, fillColor, characterSize);
}

void TextBox::setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor) {
    sf::RectangleShape::setSize(size);
    sf::RectangleShape::setPosition(position);
    sf::RectangleShape::setFillColor(defaultFillColorBox);
    // Настройка коліру вздовш ліній прямокутника
    /*sf::RectangleShape::setOutlineColor(sf::Color::Black);
    sf::RectangleShape::setOutlineThickness(2.0f);*/
}

void TextBox::setTextProperties(const std::string& content, const sf::Font& font = defaultFontText, const sf::Color& fillColor = defaultFillColorText, unsigned int characterSize = defaultCharacterSize) {
    sf::Text::setString(content);
    sf::Text::setFont(font);
    sf::Text::setFillColor(fillColor);
    sf::Text::setCharacterSize(characterSize);

    // Центруємо текст у прямокутнику
    sf::FloatRect textBounds = sf::RectangleShape::getLocalBounds();
    sf::RectangleShape::setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    sf::RectangleShape::setPosition(sf::RectangleShape::getPosition().x + sf::RectangleShape::getSize().x / 2.0f, sf::RectangleShape::getPosition().y + sf::RectangleShape::getSize().y / 2.0f);
}