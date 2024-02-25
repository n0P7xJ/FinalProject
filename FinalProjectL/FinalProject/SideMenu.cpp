#include "SideMenu.h"


SideMenu::SideMenu(const sf::Vector2f& size, const sf::Vector2f& position) : TextBox(size, position), isVisible(false),RectMenu(size),
settingButton(sf::Vector2f(180, 50), sf::Vector2f(10, 230), "Settings"),
calendarButton(sf::Vector2f(180, 50), sf::Vector2f(10, 170), "Calendar"),
homeButton(sf::Vector2f(180, 50), sf::Vector2f(10, 110), "Main"){
    RectMenu.setSize(size);
    RectMenu.setPosition(position);
    RectMenu.setFillColor(sf::Color(46, 139, 87));

    if (logoTexture.loadFromFile("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/logo.png")) {
        logo.setTexture(logoTexture);
    }

}

bool SideMenu::isButtonClicked(const sf::Vector2f& mousePosition) const {
    return  homeButton.checkPress(mousePosition) ||
        calendarButton.checkPress(mousePosition) ||
        settingButton.checkPress(mousePosition);
}

void SideMenu::Visible() 
{
    isVisible = !isVisible;
}

void SideMenu::draw(sf::RenderWindow& sideWindow) {
    if (isVisible) {
        sideWindow.draw(RectMenu);
        sideWindow.draw(logo);
        settingButton.draw(sideWindow);
        calendarButton.draw(sideWindow);
        homeButton.draw(sideWindow);
    }
}

void SideMenu::setBackground(const string& bg) {
    if (!backgroundTexture.loadFromFile(bg)) {
        throw(std::runtime_error("Не вдалось загрузити файл " + bg));
    }
    else
       RectMenu.setTexture(&backgroundTexture);
}

// перенести в конструктор
void SideMenu::setLogoSize(const sf::Vector2f& size) {
    logo.setScale(size.x / logoTexture.getSize().x, size.y / logoTexture.getSize().y);
}
// перенести в конструктор
void SideMenu::setLogoPosition(const sf::Vector2f& position) {
    logo.setPosition(position);
}

