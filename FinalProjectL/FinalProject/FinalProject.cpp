#include "SFML/Graphics.hpp"
#include <iostream>
#include <exception>


int main(){
    try {
        sf::RenderWindow mainWindow;
        mainWindow.create(sf::VideoMode(1024, 640), L"DailyTask");

        while (mainWindow.isOpen()) {
            sf::Event event;
            while (mainWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    mainWindow.close();
                }
            }



        }
        system("pause");
        return 0;
    }
    catch (...) {
        std::cerr << "Code have problem" << '\n';
    }
}
