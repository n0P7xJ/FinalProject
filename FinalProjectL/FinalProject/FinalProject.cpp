#include <SFML/Graphics.hpp>

#include <vector>
#include <Windows.h>
#include <iostream>

#include "TextBox.h"
#include "Days.h"


using namespace std;

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    sf::RenderWindow window(sf::VideoMode(1176, 770), "DailyTask");

    // ЗАДНІЙ ФОН
    sf::Texture BackGround;
    if (!BackGround.loadFromFile("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/gradient.png"))
    {
        //Обробка помилки, якщо не вдалося завантажити текстуру
        return -1;
    }

    sf::RectangleShape backgroundRect(sf::Vector2f(window.getSize().x, window.getSize().y));
    backgroundRect.setTexture(&BackGround);


    // Створюю двухвимірний масив кнопок, для подальшого виводу на екран
    const int LineHorizont = 6;
    const int LineVertikal = 7;
    std::vector<std::vector<TextBox*>> listBoxWindow(LineHorizont,std::vector<TextBox*>(LineVertikal));
    
    // Тимчасовий варіант заповнення

    TextBox MainBox(sf::Vector2f(1176, 110), sf::Vector2f(0, 0));
    //MainBox.sf::RectangleShape::setFillColor(sf::Color::Black);

    //sf::RectangleShape rectangleYearAndMouth;
    //// sf::RectangleShape* rectangleYearAndMourh;
    //rectangleYearAndMouth.setSize(sf::Vector2f(1170, 96));
    //rectangleYearAndMouth.setPosition(sf::Vector2f(0, 0));
    //rectangleYearAndMouth.setFillColor(sf::Color::Black);




    for (int y = 0; y < LineHorizont; ++y) {
        for (int x = 0; x < LineVertikal; ++x) {
            listBoxWindow[y][x] = new TextBox(sf::Vector2f(168, 110), sf::Vector2f(168 * x, 110 * (y+1)),"");
        }
    }

    //створюю об'єкт класу Days
    Days days(sf::Vector2f(1176, 110), sf::Vector2f(0, 0), "empty", sf::Color::White, TextBox::defaultFontText, sf::Color::Black, TextBox::defaultCharacterSize);
    days.setMonthAndYear("JANUARY", 2024, 40);  // встановлюю місяць і рік
    days.setDaysOfMonth();



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundRect); //фон
        MainBox.draw(window);

        for (int i = 0; i < LineHorizont; ++i) {
            for (int j = 0; j < LineVertikal; ++j) {
                listBoxWindow[i][j]->draw(window);
            }
        }
        days.draw(window);
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
