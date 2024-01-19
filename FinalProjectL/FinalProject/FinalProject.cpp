#include <SFML/Graphics.hpp>

#include <vector>

#include "TextBox.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1176, 768), "DailyTask");

    // Створюю двухвимірний масив кнопок, для подальшого виводу на екран
    const int LineHorizont = 7;
    const int LineVertikal = 7;
    std::vector<std::vector<TextBox*>> listBoxWindow(LineHorizont,std::vector<TextBox*>(LineVertikal));
    
    // Тимчасовий варіант заповнення

    TextBox MainBox(sf::Vector2f(1176, 96), sf::Vector2f(0, 0));
    //MainBox.sf::RectangleShape::setFillColor(sf::Color::Black);

    //sf::RectangleShape rectangleYearAndMouth;
    //// sf::RectangleShape* rectangleYearAndMourh;
    //rectangleYearAndMouth.setSize(sf::Vector2f(1170, 96));
    //rectangleYearAndMouth.setPosition(sf::Vector2f(0, 0));
    //rectangleYearAndMouth.setFillColor(sf::Color::Black);


    for (int y = 0; y < LineHorizont; ++y) {
        for (int x = 0; x < LineVertikal; ++x) {
            listBoxWindow[y][x] = new TextBox(sf::Vector2f(168, 96), sf::Vector2f(168 * x, 96 * (y+1)),"empty");
        }
    }

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        MainBox.draw(window);
        for (int i = 0; i < LineHorizont; ++i) {
            for (int j = 0; j < LineVertikal; ++j) {
                listBoxWindow[i][j]->draw(window);
            }
        }
        window.display();
    }
    
    for (int i = 0; i < LineHorizont; ++i) {
        for (int j = 0; j < LineVertikal; ++j) {
            delete listBoxWindow[i][j];
        }
    }

    listBoxWindow.clear();

    return 0;
}
