#include "Calendar.h"

const string Calendar::daysOfWeek[] = { "MONDAY", "TUESDAY", "WEDENESDAY", "THURSDAY", "FRIDAY", "SATURDAY","SUNDAY", };

Calendar::Calendar(TextBox* ptrMainBox, vector<vector<TextBox*>>* ptrMouthBoxList)
{
    setMainBox(ptrMainBox);
    setMouthBoxList(ptrMouthBoxList);
    adjustMainBox();
    adjustMouthBoxList();
}


Calendar::~Calendar() {
    // Очищення списку
    for (int y = 0; y < lineHorizontX; ++y) {
        for (int x = 0; x < lineVetrikalY; ++x) {
            delete& listBoxWindow[y][x];  // Видалення об'єкта
            (*listBoxWindow)[y][x] = nullptr; // Звільнення покажчика
        }
    }
}

void Calendar::setMonthAndYear(const string& month, int year, int textSize) {
    mainBox->setTextProperties(month + " " + to_string(year), defaultFontText, defaultFillColorText, textSize);
}

// Заповнення днів місяця
void Calendar::setDaysOfMonth(const int& month, const int& startDay) {
    int day = 1;

    // Заповнення першого рядка масиву назвами днів тижня
    for (int i = 0; i < 7; ++i) {
        (*listBoxWindow)[0][i]->setTextProperties(daysOfWeek[i], defaultFontText, defaultFillColorText, defaultCharacterSize);
    }

    // Заповнення днів місяця
    for (int i = 1; i < lineHorizontX; ++i) { // 6 рядків у календарі
        for (int j = 0; j < lineVetrikalY; ++j) { // 7 днів у тижні
            if (day <= month) { // Перевіряємо, чи ще не закінчились дні місяця
                if (i == 1 && j < startDay - 1) { // Якщо це перший рядок і позиція є до початкового дня місяця
                   /* int pastMouth = (getMonthDay((systemTime.getMonth() - 1) == -1 ? 12 : systemTime.getMonth() - 1, systemTime.getYear())-startDay)+(7-startDay);*/
                    (*listBoxWindow)[i][j]->setTextProperties(""/*to_string(pastMouth+j)*/, defaultFontText, defaultFillColorText, defaultCharacterSize);
                }
                else {
                    (*listBoxWindow)[i][j]->setTextProperties(to_string(day), defaultFontText, defaultFillColorText, defaultCharacterSize);
                    ++day;
                }
            }
            else {
                (*listBoxWindow)[i][j]->setTextProperties("", defaultFontText, defaultFillColorText, defaultCharacterSize); // Залишаємо решту клітинок порожніми
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

void Calendar::isBoxPressed(const sf::Vector2f& mousePosition) const{
    for (vector<TextBox*> list : (*listBoxWindow)) {
        for (TextBox* itList : list) {
            if (itList->checkPress(mousePosition)) {
                std::cout << "Press box " + std::string(itList->getString()) + '\n';
                return;
            }
        }
    }
}

void Calendar::adjustMouthBoxList() //������������
{
    for (int y = 0; y < lineHorizontX; ++y)
    {
        for (int x = 0; x < lineVetrikalY; ++x)
        {
            (*listBoxWindow)[y][x] = new TextBox(sf::Vector2f(sizeBoxX, sizeBoxY), sf::Vector2f(sizeBoxX * x, sizeBoxY * (y + 1)), "");
        }
    }
}

void Calendar::adjustMainBox() //�������� �����������
{
    mainBox->setSize(sf::Vector2f(sizeWindowX, sizeBoxMainY));
    mainBox->sf::RectangleShape::setPosition(sf::Vector2f(0, 0));
}


void Calendar::draw(sf::RenderWindow& window)
{
    mainBox->draw(window);
    for (int i = 0; i < lineHorizontX; ++i)
    {
        for (int j = 0; j < lineVetrikalY; ++j)
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
