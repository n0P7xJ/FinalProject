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
#include "ShowTask.h"
#include "Task.h"'
#include "TaskManager.h"
using namespace std;




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int currentYear = systemTime.getYear();
    int currentMouth = systemTime.getMonth();
    int currentDay = systemTime.getDay();
    StatusProgram statusProgram = calendar;
    bool menuOn = false;
    sf::RenderWindow window(sf::VideoMode(sizeWindowX, sizeWindowY), "DailyTask");
   
    TextBox* mainBox = new TextBox();
    vector<vector<TextBox*>>* listBoxWindow = new vector<vector<TextBox*>>(lineHorizontX, vector<TextBox*>(lineVetrikalY));

    Calendar* mycalendar = new Calendar(mainBox, listBoxWindow);
    mycalendar->setMonthAndYear(systemTime.getMonthName(currentMouth), currentYear, 40);
    mycalendar->setDaysOfMonth(getMonthDay(currentMouth, currentMouth), systemTime.getDayOfWeekForFirstDayOfMonth(currentMouth));
    TextBox nextButton(sf::Vector2f(40, 40), sf::Vector2f(1000, 50), "/\\");
    TextBox backButton(sf::Vector2f(40, 40), sf::Vector2f(1050, 50), "\\/");

    SideMenu menuSide(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 0));
    //фон для бічного меню
    menuSide.setBackground(fonsPNG);
    //логотип калібровка
    menuSide.setLogoSize(sf::Vector2f(100, 100));
    menuSide.setLogoPosition(sf::Vector2f(60, 1));

    window.setVerticalSyncEnabled(true);
    

    ShowTask myShowTask(sf::Vector2f(0,0), sf::Vector2f(520, 40));
    std::vector<Task*>* listTask = new std::vector<Task*>;
    TaskManager taskManager;
    taskManager.setlistTask(listTask);
   


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
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (menuOn) {
                        statusProgram = menuSide.isButtonClicked(mousePosition);
                        break;
                    }
                    switch (statusProgram)
                    {
                    case calendar: {
                        if (nextButton.checkPress(mousePosition)) {
                            if (currentMouth + 1 == 13) {
                                currentMouth = 1;
                                ++currentYear;
                            }
                            else {
                                ++currentMouth;
                            }
                            mycalendar->setMonthAndYear(systemTime.getMonthName(currentMouth), currentYear, 40);
                            mycalendar->setDaysOfMonth(getMonthDay(currentMouth, currentMouth), systemTime.getDayOfWeekForFirstDayOfMonth(currentMouth));
                        }
                        else if (backButton.checkPress(mousePosition)) {
                            if (currentMouth - 1 <= 0) {
                                currentMouth = 12;
                                --currentYear;
                            }
                            else {
                                --currentMouth;
                            }
                            mycalendar->setMonthAndYear(systemTime.getMonthName(currentMouth), currentYear, 40);
                            mycalendar->setDaysOfMonth(getMonthDay(currentMouth, currentMouth), systemTime.getDayOfWeekForFirstDayOfMonth(currentMouth));
                        }
                        else {
                            TextBox* clickBox = mycalendar->isBoxPressed(mousePosition);
                            if (clickBox != nullptr)
                            {
                                if (clickBox->getString() == ""
                                    || clickBox->getString() == "MONDAY"
                                    || clickBox->getString() == "TUESDAY"
                                    || clickBox->getString() == "WEDNESDAY"
                                    || clickBox->getString() == "THURSDAY"
                                    || clickBox->getString() == "FRIDAY"
                                    || clickBox->getString() == "SATURDAY"
                                    || clickBox->getString() == "SUNDAY"
                                    )
                                {
                                    cout << "Натиснуто на назву дня тижня або пусту комірку" << endl;
                                }
                                else
                                {
                                    int day = stoi(clickBox->getString().toAnsiString());
                                    myShowTask.setDateInfo(systemTime.getMonthName(currentMouth), day, systemTime.getYear()); // Встановлює дату при нажатті на комірки
                                    taskManager.readFile("TaskList/" + clickBox->getString() + '.' + std::to_string(currentMouth) + '.' + std::to_string(currentYear) + ".txt");
                                    std::wstring stringTask;
                                    for (Task* task : (*listTask)) {
                                        stringTask += task->getTask() + L'\n';
                                    }
                                    if (stringTask.empty()) { stringTask = L"empty"; }
                                    myShowTask.setTaskInfo(stringTask);
                                    statusProgram = task;

                                }
                            }
                            else
                            {
                                cout << "Nothing is pressed" << endl;
                            }
                            break;
                        }
                    }
                    }
                }
            }
        }
        switch (statusProgram) {
        case calendar: {
            window.clear(sf::Color::Black);
            mycalendar->draw(window);
            if (menuOn) { menuSide.draw(window); }
            if (systemTime.getYear() == currentYear && systemTime.getMonth() == currentMouth) { mycalendar->setCurrentDay(currentDay); myShowTask.setDateInfo(systemTime.getMonthName(currentMouth), currentDay, currentYear); } // Встановлює поточну дату в  вікні TASK}
            nextButton.draw(window);
            backButton.draw(window);
            window.display();
            break;
        }
        case task: {
            window.clear(sf::Color::White);

            sf::Texture backg;
            if (!backg.loadFromFile(fonPNG))
            {
                throw(std::runtime_error("Не вдалось загрузити файл "));
            }
            else {
                sf::Sprite backgroundSprite(backg);
                window.draw(backgroundSprite);
            }
            if (menuOn) { menuSide.draw(window); }
   
            myShowTask.draw(window);
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
    delete listTask;

    return 0;
}