#include "TextBox.h"

TextBox::TextBox(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& content, const sf::Color& fillColorBox, const sf::Font& font, const sf::Color& fillColor, unsigned int characterSize) {
    setRectangleProperties(size, position, fillColorBox);
    setTextProperties(content, font, fillColor, characterSize);
}

void TextBox::setRectangleProperties(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor) {
    sf::RectangleShape::setSize(size);
    sf::RectangleShape::setPosition(position);
    sf::RectangleShape::setFillColor(fillColor);
    // Настройка коліру вздовш ліній прямокутника
    sf::RectangleShape::setOutlineColor(sf::Color::Black);
    sf::RectangleShape::setOutlineThickness(1.0f);
}

void TextBox::setTextProperties(const std::string& content, const sf::Font& font, const sf::Color& fillColor,const unsigned int& characterSize) {
    sf::Text::setString(content);
    sf::Text::setFont(font);
    sf::Text::setFillColor(fillColor);
    sf::Text::setCharacterSize(characterSize);

    // Центруємо текст у прямокутнику
    sf::FloatRect textBounds = sf::Text::getLocalBounds();
    sf::Text::setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    sf::Text::setPosition(sf::RectangleShape::getPosition().x + sf::RectangleShape::getSize().x / 2.0f, sf::RectangleShape::getPosition().y + sf::RectangleShape::getSize().y / 2.0f);
}

bool TextBox::checkPress(const sf::Vector2f& mousePosition) const
{
    // Отримуємо границі прямокутник
    sf::FloatRect rectBounds = sf::RectangleShape::getGlobalBounds();
    // Перевіряємо, чи миша знаходиться в межах прямокутника
    return rectBounds.contains(mousePosition);
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    // Тут ви маєте викликати методи малювання вашого об'єкта
    target.draw(static_cast<sf::RectangleShape>(*this), states);
    target.draw(static_cast<sf::Text>(*this), states);
}
