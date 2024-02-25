#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>
#include <iostream>

#include "SystemTime.h"
#include "TextBox.h"
#include "Calendar.h"
#include "SideMenu.h"
#include "settings.h"
#include "Calendar.h"

using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StatusProgram statusProgram = calendar;

    sf::RenderWindow window(sf::VideoMode(sizeWindowX, sizeWindowY), "DailyTask");

    TextBox* mainBox = new TextBox();
    vector<vector<TextBox*>>* listBoxWindow = new vector<vector<TextBox*>>(lineHorizont, vector<TextBox*>(lineVetrikal));


    Calendar* mycalendar = new Calendar(mainBox, listBoxWindow);
    mycalendar->setMonthAndYear("February", 2024, 40);
    mycalendar->setDaysOfMonth();


    //створюю об'єкт класу Days #2 масив
    //Days days(sf::Vector2f(sizeWindowX, sizeBoxY), sf::Vector2f(0, 0), "empty", sf::Color::White, TextBox::defaultFontText, sf::Color::Black, TextBox::defaultCharacterSize);
    //days.setMonthAndYear(systemTime.getMonthName(systemTime.getMonth()), systemTime.getYear(), 40);  // встановлюю місяць і рік
    //days.setDaysOfMonth(getMonthDay());
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch (statusProgram) {
        case calendar: {


            window.clear();

            mycalendar->draw(window);

            window.display();

        }
        default:
            break;
        }
    }

    delete mainBox;
    delete listBoxWindow;
    delete mycalendar;

    //SideMenu menuSide(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 0));
    ////фон для бічного меню
    //menuSide.setBackground("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/gradient.png");

    ////логотип #1 калібровка
    //menuSide.setLogoSize(sf::Vector2f(100, 100));
    //menuSide.setLogoPosition(sf::Vector2f(60, 1));

    //window.setVerticalSyncEnabled(true);

    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //        if (event.type == sf::Event::KeyPressed)
    //        {
    //            if (event.key.code == sf::Keyboard::Escape)
    //            {
    //                menuSide.Visible();
    //            }
    //        }
    //        if (event.type == sf::Event::MouseButtonPressed) {
    //            if (event.mouseButton.button == sf::Mouse::Left) {
    //                // Отримуємо позицію миші
    //                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    //  
    //                if (menuSide.calendarButton.checkPress(mousePosition)) {
    //                    cout << "Calendar button clicked" << endl;
    //  
    //                }
    //                else if (menuSide.settingButton.checkPress(mousePosition)) {
    //                    cout << "Settings button clicked" << endl;
    //                
    //                }
    //                else if (menuSide.homeButton.checkPress(mousePosition)) {
    //                   cout << "Home button clicked" << endl;
    //                 
    //                }
    //                // Перевіряємо, чи натиснуто на прямокутник
    //                /*bool search = false;
    //                for (std::vector<TextBox*> listBox : days.getList()) {
    //                    if (search) {
    //                        for (TextBox* box : listBox) {
    //                            if (box->checkPress(mousePosition)) {
    //                                std::cout << "Rectangle clicked!" << std::endl;
    //                                search = false;
    //                            }
    //                        }
    //                    }
    //                    else {
    //                        search = true;
    //                    }
    //                }*/
    //            }
    //        }
    //    }
    //    window.clear();
    //    /*days.draw(window);*/
    //    //меню бічне
    //    menuSide.draw(window);
    //    window.display();
    //}

    return 0;
}