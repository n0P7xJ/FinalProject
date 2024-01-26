#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include <iostream>

using namespace std;

class Days
{
public:

    Days(const sf::Vector2f& size, const sf::Vector2f& position, const string& content, const sf::Color& fillColorBox, const sf::Font& font, const sf::Color& fillColor, unsigned int characterSize);

    void setMonthAndYear(const string& month, int year, int textSize);
    void setDaysOfMonth();
    void draw(sf::RenderWindow& window);

private:
    TextBox mainBox;
    vector<vector<TextBox*>> listBoxWindow;
    string currentMonth;
    int currentYear;
    int LineHorizont;
    int LineVertikal;
    static const string daysOfWeek[];
};