#pragma once
#include "settings.h"
#include "TextBox.h"

class ShowTask
{
public:
	ShowTask(const sf::Vector2f& size, const sf::Vector2f& position);
	void draw (sf::RenderWindow& window) const;
	//Дата
	void setDateInfo(const std::string& month, int day, int year);
	void setTaskInfo(const std::wstring& task);
	//Прямокутники
	void setRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void InSetRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void inSetRectanglesTwo(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void inSetRectanglesThree(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void inSetRectanglesFour(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void inSetRectanglesFive(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void inSetRectanglesSix(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	//Натиск на кнопки
	bool pressCreateButton(sf::Vector2f mousePosition) const;
	bool pressDeleteButton(sf::Vector2f mousePosition) const;
protected:
	//Текст дати
	sf::Text dateText;
	sf::Text taskText;
	//Кнопки
	TextBox createTaskButton;
	TextBox deleteTaskButton;
	TextBox upButton;
	TextBox downButton;
	//Прямокутники
	sf::RectangleShape rectangle;
	sf::RectangleShape inRectangle; //� ������������
	sf::RectangleShape inRectangleTwo;
	sf::RectangleShape inRectangleThree;
	sf::RectangleShape inRectangleFour;
	sf::RectangleShape inRectangleFive;
	sf::RectangleShape inRectangleSix;
};

