#include "Screen.h"

Screen::Screen(sf::RenderWindow& mainWindow) : mainWindow(mainWindow)
{
	selectedItemIndex = 0;
	isMainStarted = false;
}

void Screen::handleInput()
{
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {

            mainWindow.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                if (selectedItemIndex > 0) {
                    selectedItemIndex--;
                }
            }
            else if (event.key.code == sf::Keyboard::Down) {
                if (selectedItemIndex < 2) {
                    selectedItemIndex++;
                }
            }

            else if (event.key.code == sf::Keyboard::Return) {
                if (selectedItemIndex == 0) {
                    mainStart(); // Запуск гри при виборі пункту "Грати"
                }
                if (selectedItemIndex == 1) {
                    ///відкрити нове вікно в якому буде вибір рівнів
                }

                else if (selectedItemIndex == 2) {
                    mainWindow.close(); // Закриття вікна при виборі пункту "Вихід"
                }
            }
        }
    }
}


void Screen::mainStart(){
    isMainStarted = true; // Прапорець, що вказує, що гра розпочата

}

void Screen::draw() {
    mainWindow.clear();

    mainWindow.display();
}
