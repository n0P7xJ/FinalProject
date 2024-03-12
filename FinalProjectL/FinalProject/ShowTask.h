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
protected:
	sf::Text dateText;
	sf::Text taskText;
	TextBox createTaskButton;
	TextBox deleteTaskButton;
};

