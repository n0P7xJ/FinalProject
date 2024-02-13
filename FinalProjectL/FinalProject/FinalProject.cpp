#include <SFML/Graphics.hpp>

#include <vector>
#include <Windows.h>
#include <iostream>

#include "SystemTime.h"
#include "TextBox.h"
#include "Days.h"
#include "SideMenu.h"

using namespace std;

SystemTime systemTime;

#define sizeWindowX 1176
#define sizeWindowY 770

#define sizeBoxX 168
#define sizeBoxY 110

#define lineHorizont  6
#define lineVetrikal  7

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    sf::RenderWindow window(sf::VideoMode(sizeWindowX, sizeWindowY), "DailyTask");

    //// ЗАДНІЙ ФОН
    //sf::Texture BackGround;
    //if (!BackGround.loadFromFile("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/gradient.png"))
    //{
    //    //Обробка помилки, якщо не вдалося завантажити текстуру
    //    return -1;
    //}
    //sf::RectangleShape backgroundRect(sf::Vector2f(window.getSize().x, window.getSize().y));
    //backgroundRect.setTexture(&BackGround);
    // Створюю двухвимірний масив кнопок, для подальшого виводу на екран

    std::vector<std::vector<TextBox*>> listBoxWindow(lineHorizont,std::vector<TextBox*>(lineVetrikal));
    
    TextBox MainBox(sf::Vector2f(sizeWindowX, sizeBoxY), sf::Vector2f(0, 0));

    for (int y = 0; y < lineHorizont; ++y) {
        for (int x = 0; x < lineVetrikal; ++x) {
            listBoxWindow[y][x] = new TextBox(sf::Vector2f(sizeBoxX, sizeBoxY), sf::Vector2f(sizeBoxX * x, sizeBoxY * (y+1)),"");
        }
    }

    //створюю об'єкт класу Days
    Days days(sf::Vector2f(sizeWindowX, sizeBoxY), sf::Vector2f(0, 0), "empty", sf::Color::White, TextBox::defaultFontText, sf::Color::Black, TextBox::defaultCharacterSize);
    days.setMonthAndYear(systemTime.getMonthName(systemTime.getMonth()), systemTime.getYear(), 40);  // встановлюю місяць і рік
    days.setDaysOfMonth();

    SideMenu menuSide(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 0));

    //фон для бічного меню
    menuSide.setBackground("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/gradient.png");


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    menuSide.Visible();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Отримуємо позицію миші
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    // Перевіряємо, чи натиснуто на прямокутник
                    bool search = true;
                    for (std::vector<TextBox*> listBox : listBoxWindow) {
                        if (search) {
                            for (TextBox* box : listBox) {
                                if (box->checkPress(mousePosition)) {
                                    std::cout << "Rectangle clicked!" << std::endl;
                                    search = false;
                                }
                            }
                        }
                    }
                }
            }
        }

        window.clear();
        days.draw(window);
        //меню бічне
        menuSide.draw(window);
        window.display();
    }
    
    for (int i = 0; i < lineHorizont; ++i) {
        for (int j = 0; j < lineVetrikal; ++j) {
            delete listBoxWindow[i][j];
        }
    }

    listBoxWindow.clear();

    return 0;
}
