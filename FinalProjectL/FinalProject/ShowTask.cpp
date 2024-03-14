#include "ShowTask.h"


ShowTask::ShowTask(const sf::Vector2f& size, const sf::Vector2f& position) :
	createTaskButton(sf::Vector2f(130, 40), sf::Vector2f(position.x + (-280), position.y + 110), "Create task"),
	deleteTaskButton(sf::Vector2f(130, 40), sf::Vector2f(position.x + (-140), position.y + 110), "Delete Task")
{
	//DATA
	dateText.setFont(defaultFontText);
	dateText.setCharacterSize(35);
	dateText.setFillColor(sf::Color::White);
	dateText.setPosition(position);
	//TASK
	taskText.setFont(defaultFontText);
	taskText.setCharacterSize(18);
	taskText.setFillColor(sf::Color::White);
	taskText.setPosition(300,position.y+239);
	//RECTANGLE
	setRectangles(sf::Vector2f(900, 400), sf::Vector2f(position.x + (-280), position.y + 190), sf::Color::Transparent);
	InSetRectangles(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 230), sf::Color::Transparent);
}


void ShowTask::draw(sf::RenderWindow& window) const
{
	window.draw(dateText);
	window.draw(taskText);
	createTaskButton.draw(window);
	deleteTaskButton.draw(window);
	window.draw(rectangle);
	window.draw(inRectangle);
}

void ShowTask::setDateInfo(const std::string& month, int day, int year)
{
	//���������� ��� ����, ����� � ��
	std::string taskInfo = std::to_string(day) + " " + month + " " + std::to_string(year);

   //��� ���������
	dateText.setString(taskInfo);
}

void ShowTask::setTaskInfo(const std::wstring& task){
	taskText.setString(task);
}

void ShowTask::setRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{
	// Створення прямокутника
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(fillColor);

	// Налаштування коліру вздовж ліній прямокутника
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(2.0f);
}

void ShowTask::InSetRectangles(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{
	// Створення прямокутника
	inRectangle.setSize(size);
	inRectangle.setPosition(position);
	inRectangle.setFillColor(fillColor);

	// Налаштування коліру вздовж ліній прямокутника
	inRectangle.setOutlineColor(sf::Color::White);
	inRectangle.setOutlineThickness(2.0f);
}

