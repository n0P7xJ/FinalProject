#pragma once
#include "settings.h"
#include "TextBox.h"

class ShowTask : public TextBox
{
public:
	ShowTask(const sf::Vector2f& size, const sf::Vector2f& position);
	void draw (sf::RenderWindow& window) const;
	void setTaskInfo(const std::string& month, int day, int year);
protected:
	sf::Text dateText;
	TextBox createTaskButton;
	TextBox deleteTaskButton;
};

