#include "TextBox.h"

//Text Default Value
 const unsigned int TextBox::defaultCharacterSize = 20;
 const sf::Color TextBox::defaultFillColorText = sf::Color::Black;
 const sf::Font TextBox::defaultFontText = [] {
    sf::Font font;
    if (!font.loadFromFile("Font/Oswald.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    return font;
}();
 const std::string TextBox::defaultString = "";
//Rectangle Default Value
 const sf::Color TextBox::defaultFillColorBox = sf::Color::White;
 const sf::Vector2f TextBox::defaultSize(1.f,1.f);
//Other 
 const sf::Vector2f defaultPosition(0.f, 0.f);

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

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    // Тут ви маєте викликати методи малювання вашого об'єкта
    target.draw(static_cast<sf::RectangleShape>(*this), states);
    target.draw(static_cast<sf::Text>(*this), states);
}
