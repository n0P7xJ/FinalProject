#include "Calendar.h"

const string Calendar::daysOfWeek[] = { "SUNDAY", "MONDAY", "TUESDAY", "WEDENESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };

Calendar::Calendar(TextBox* ptrMainBox, vector<vector<TextBox*>>* ptrMouthBoxList)
{
    setMainBox(ptrMainBox);
    setMouthBoxList(ptrMouthBoxList);
    adjustMainBox();
    adjustMouthBoxList();
}


Calendar::~Calendar() {
    // Очищення списку
    for (int y = 0; y < lineHorizont; ++y) {
        for (int x = 0; x < lineVetrikal; ++x) {
            delete& listBoxWindow[y][x];  // Видалення об'єкта
            (*listBoxWindow)[y][x] = nullptr; // Звільнення покажчика
        }
    }
}

void Calendar::setMonthAndYear(const string& month, int year, int textSize) {
    mainBox->setTextProperties(month + " " + to_string(year), defaultFontText, defaultFillColorText, textSize);
}


void Calendar::setDaysOfMonth(const int& mouth, const int& startDay)
{
    for (int x = 0; x < lineVetrikal; ++x)
    {
        (*listBoxWindow)[0][x]->setTextProperties(daysOfWeek[x], defaultFontText, defaultFillColorText, defaultCharacterSize);
    }

    int day = 1;

    for (int i = 0; i < 6; ++i) { // ���� 5 ����� � �����(31 ����)
        for (int j = 0; j < 7; ++j) { //7 ��� � ����
            if (i == 0)
            {//����� �����

                (*listBoxWindow)[i][j]->setTextProperties(daysOfWeek[j], defaultFontText, defaultFillColorText, defaultCharacterSize);
            }
            else
            {
                if (day <= 31) // �� �����
                {

                    (*listBoxWindow)[i][j]->setTextProperties(to_string(day), defaultFontText, defaultFillColorText, defaultCharacterSize);
                    day++;
                }
                else //���� ��� � 31 ���� ��������� �� ������ �����
                {
                    (*listBoxWindow)[i][j]->setTextProperties("", defaultFontText, defaultFillColorText, defaultCharacterSize);
                }
            }
        }
    }
}

void Calendar::setMainBox(TextBox* ptrMainBox)
{
    if (ptrMainBox != nullptr)
    {
        mainBox = ptrMainBox;
    }
    else
        throw(std::runtime_error("PtrMainBox its nullptr"));
}

void Calendar::setMouthBoxList(vector<vector<TextBox*>>* ptrMouthBoxList)
{
    //�������� �� ��� ���
    if (ptrMouthBoxList != nullptr) {
        listBoxWindow = ptrMouthBoxList;
    }
    else
        throw(std::runtime_error("PtrMouthBoxList its nullptr"));
}

void Calendar::adjustMouthBoxList() //������������
{
    for (int y = 0; y < lineHorizont; ++y)
    {
        for (int x = 0; x < lineVetrikal; ++x)
        {
            (*listBoxWindow)[y][x] = new TextBox(sf::Vector2f(sizeBoxX, sizeBoxY), sf::Vector2f(sizeBoxX * x, sizeBoxY * (y + 1)), "");
        }
    }
}

void Calendar::adjustMainBox() //�������� �����������
{
    mainBox->setSize(sf::Vector2f(sizeWindowX, sizeBoxY));
    mainBox->sf::RectangleShape::setPosition(sf::Vector2f(0, 0));
}


void Calendar::draw(sf::RenderWindow& window)
{
    mainBox->draw(window);
    for (int i = 0; i < lineHorizont; ++i)
    {
        for (int j = 0; j < lineVetrikal; ++j)
        {
            if (i == 0) { //���� ���� ���� �����
                if (daysOfWeek[j] == "SUNDAY" || daysOfWeek[j] == "SATURDAY") {
                    (*listBoxWindow)[i][j]->setRectangleProperties(sf::Vector2f(168, 110), sf::Vector2f(168 * j, 110), sf::Color(183, 35, 34)); // �������� ���� ��� ����� �� ������
                }
                else {
                    (*listBoxWindow)[i][j]->setRectangleProperties(sf::Vector2f(168, 110), sf::Vector2f(168 * j, 110), sf::Color(118, 168, 230)); // ����������� ���� ��� ����� ���
                }
            }
            (*listBoxWindow)[i][j]->draw(window);
        }
    }
}
