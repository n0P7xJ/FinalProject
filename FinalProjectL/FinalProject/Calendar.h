#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include <iostream>
#include "settings.h"

using namespace std;

class Calendar 
{
public:

    Calendar(TextBox* ptrMainBox, vector<vector<TextBox*>>* ptrMouthBoxList);

    ~Calendar();

    void draw(sf::RenderWindow& window);

    void setMonthAndYear(const string& month, int year, int textSize); // ���������� ����� � ��
    void setDaysOfMonth(const int& mouth = 0, const int &startDay = 0); // ���������� �-��� ��� ������ + ������� �����
    void setMainBox(TextBox* ptrMainBox); //���������� �������� �� �������� �����������(MainBox)
    void setMouthBoxList(vector<vector<TextBox*>>* ptrMouthBoxList); // ���������� �������� �� ����� ������������

protected:
    void adjustMouthBoxList(); //��������� ��������� ������������
    void adjustMainBox(); //��������� ��������� ��������� ������������
private:
    TextBox* mainBox;
    vector<vector<TextBox*>>* listBoxWindow;
    static const string daysOfWeek[];
};