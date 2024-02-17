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
                    mainStart(); // ������ ��� ��� ����� ������ "�����"
                }
                if (selectedItemIndex == 1) {
                    ///������� ���� ���� � ����� ���� ���� ����
                }

                else if (selectedItemIndex == 2) {
                    mainWindow.close(); // �������� ���� ��� ����� ������ "�����"
                }
            }
        }
    }
}


void Screen::mainStart(){
    isMainStarted = true; // ���������, �� �����, �� ��� ���������

}

void Screen::draw() {
    mainWindow.clear();

    mainWindow.display();
}
