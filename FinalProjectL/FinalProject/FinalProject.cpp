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
    bool menuOn = false;
    sf::RenderWindow window(sf::VideoMode(sizeWindowX, sizeWindowY), "DailyTask");

    TextBox* mainBox = new TextBox();
    vector<vector<TextBox*>>* listBoxWindow = new vector<vector<TextBox*>>(lineHorizontX, vector<TextBox*>(lineVetrikalY));

    Calendar* mycalendar = new Calendar(mainBox, listBoxWindow);
    mycalendar->setMonthAndYear(systemTime.getMonthName(3), systemTime.getYear(), 40);
    mycalendar->setDaysOfMonth(getMonthDay(3, systemTime.getYear()), systemTime.getDayOfWeekForFirstDayOfMonth(3));

    SideMenu menuSide(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 0));
    //фон для бічного меню
    menuSide.setBackground("C:/Program Files/FinalProject/FinalProjectL/FinalProject/Image/gradient.png");
    //логотип калібровка
    menuSide.setLogoSize(sf::Vector2f(100, 100));
    menuSide.setLogoPosition(sf::Vector2f(60, 1));

    window.setVerticalSyncEnabled(true);

    //створюю об'єкт класу Days #2 масив
    //Days days(sf::Vector2f(sizeWindowX, sizeBoxY), sf::Vector2f(0, 0), "empty", sf::Color::White, TextBox::defaultFontText, sf::Color::Black, TextBox::defaultCharacterSize);
    //days.setMonthAndYear(systemTime.getMonthName(systemTime.getMonth()), systemTime.getYear(), 40);  // встановлюю місяць і рік
    //days.setDaysOfMonth(getMonthDay());
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "Click escape\n";
                    menuOn = menuSide.Visible();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (menuOn) {
                        statusProgram = menuSide.isButtonClicked(mousePosition);
                        break;
                    }
                    switch (statusProgram){
                    case calendar:
                        mycalendar->isBoxPressed(mousePosition);
                        break;
                   }
                }
            }
        }
        switch (statusProgram) {
        case calendar: {
            window.clear(sf::Color::Black);
            mycalendar->draw(window);
            if (menuOn) { menuSide.draw(window); }
            window.display();
            break;
        }
        case task: {
            window.clear(sf::Color::White);
            if (menuOn) { menuSide.draw(window); }
            window.display();
            break;
        }
        case setting: {
            window.clear(sf::Color::White);
            if (menuOn) { menuSide.draw(window); }
            window.display();
            break;
        }
        default:
            break;
        }
    }
    delete mainBox;
    delete listBoxWindow;
//   delete mycalendar;

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