#include <SFML/Graphics.hpp>


int main(){
    sf::RenderWindow window(sf::VideoMode(1170, 768), "DailyTask");

    // Створюю двухвимірний масив кнопок, для подальшого виводу на екран
    const int LineHorizont = 7;
    const int LineVertikal = 7;
    sf::RectangleShape listRectangl[LineHorizont][LineVertikal]; // Статичний оскільки масив не буде міняти свої розміри
    // sf::RectangleShape (*ptrListRectangle)[LineVertikal] = listRectangl; Вказівник на масив якщо буде потрібен нараз в коментарі
    // Структура вказівника (вказівник на масив)[розмір масива], не створив динамічний оскільки розмір не буде мінятися
    
    // Тимчасовий варіант заповнення

    sf::RectangleShape rectangleYearAndMouth;
    // sf::RectangleShape* rectangleYearAndMourh;
    rectangleYearAndMouth.setSize(sf::Vector2f(1170, 96));
    rectangleYearAndMouth.setPosition(sf::Vector2f(0, 0));
    rectangleYearAndMouth.setFillColor(sf::Color::Black);

    for (int i = 0; i < LineHorizont; ++i) {
        for (int j = 0; j < LineVertikal; ++j) {
            sf::RectangleShape rectangl;
            

            //listRectangl[i][j]
        }
    }


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(rectangleYearAndMouth);
        window.display();
    }
    

    return 0;
}
