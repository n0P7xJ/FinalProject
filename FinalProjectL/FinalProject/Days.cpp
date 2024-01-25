#include "Days.h"

const string Days::daysOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

Days::Days(const sf::Vector2f& size, const sf::Vector2f& position, const string& content, const sf::Color& fillColorBox, const sf::Font& font, const sf::Color& fillColor, unsigned int characterSize)
    : mainBox(size, position, content, fillColorBox, font, fillColor, characterSize) {

    const int LineHorizont = 6;
    const int LineVertikal = 7;

    listBoxWindow.resize(LineHorizont, vector<TextBox*>(LineVertikal));

    for (int x = 0; x < LineVertikal; ++x) {
        listBoxWindow[0][x] = new TextBox(sf::Vector2f(168, 110), sf::Vector2f(168 * x, 110), daysOfWeek[x]);
    }
    for (int y = 1; y < LineHorizont; ++y) {
        for (int x = 0; x < LineVertikal; ++x) {
            listBoxWindow[y][x] = new TextBox(sf::Vector2f(168, 110), sf::Vector2f(168 * x, 110 * (y + 1)), "empty");
        }
    }

    // розміри і положення для mainBox
    mainBox.setRectangleProperties(size, position, fillColorBox);
}

void Days::setMonthAndYear(const string& month, int year) 
{
    currentMonth = month;
    currentYear = year;
    mainBox.setTextProperties(month + " " + to_string(year), TextBox::defaultFontText, TextBox::defaultFillColorText, TextBox::defaultCharacterSize);
}



void Days::setDaysOfMonth() {


    for (int x = 0; x < LineVertikal; ++x) 
    {
        listBoxWindow[0][x]->setTextProperties(daysOfWeek[x], TextBox::defaultFontText, TextBox::defaultFillColorText, TextBox::defaultCharacterSize);
    }

    int day = 1;

    for (int i = 0; i < 6; ++i) { // типу 5 тижнів в місяці(31 день)
        for (int j = 0; j < 7; ++j) { //7 днів в тижні
            if (i == 0)
            {//назви тижнів

                listBoxWindow[i][j]->setTextProperties(daysOfWeek[j], TextBox::defaultFontText, TextBox::defaultFillColorText, TextBox::defaultCharacterSize);
            }
            else {
                if (day <= 31) // дні тижня
                {

                    listBoxWindow[i][j]->setTextProperties(to_string(day), TextBox::defaultFontText, TextBox::defaultFillColorText, TextBox::defaultCharacterSize);
                    day++;
                }
                else //якщо вже є 31 день заповнено то дальше новий
                {
                    listBoxWindow[i][j]->setTextProperties("", TextBox::defaultFontText, TextBox::defaultFillColorText, TextBox::defaultCharacterSize);
                }
            }
        }
    }
}


void Days::draw(sf::RenderWindow& window) {
    mainBox.draw(window);
    for (int i = 0; i < listBoxWindow.size(); ++i) {
        for (int j = 0; j < listBoxWindow[i].size(); ++j) {
            listBoxWindow[i][j]->draw(window);
        }
    }
}


//listBoxWindow.resize(LineHorizont, vector<TextBox*>(LineVertikal)); 
//розширює двовимірний вектор listBoxWindow до розміру який вказаний і 
//створює потрібну к-сть рядків та стовпців і заповнює їх об'єктами з TextBox