#pragma once
#include "settings.h"
#include "TextBox.h"

class ShowTask
{
public:
	ShowTask(const sf::Vector2f& size, const sf::Vector2f& position);
	void draw (sf::RenderWindow& window) const;
	void setDateInfo(const std::string& month, int day, int year);
	void setTaskInfo(const std::wstring& task);
	void setRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
	void InSetRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor);
protected:
	sf::Text dateText;
	sf::Text taskText;
	TextBox createTaskButton;
	TextBox deleteTaskButton;
	sf::RectangleShape rectangle;
	sf::RectangleShape inRectangle; //в прямокутнику
};

