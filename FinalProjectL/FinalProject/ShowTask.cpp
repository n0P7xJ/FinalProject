#include "ShowTask.h"


ShowTask::ShowTask(const sf::Vector2f& size, const sf::Vector2f& position) :
	createTaskButton(sf::Vector2f(200, 50), sf::Vector2f(position.x + 100, position.y + 100), "Create task"),
	deleteTaskButton(sf::Vector2f(200, 50), sf::Vector2f(position.x + 100, position.y + 150), "Delete Task")
{
	dateText.setFont(defaultFontText);
	dateText.setCharacterSize(35);
	dateText.setFillColor(sf::Color::Black);
	dateText.setPosition(position);
	taskText.setFont(defaultFontText);
	taskText.setCharacterSize(35);
	taskText.setFillColor(sf::Color::Black);
	taskText.setPosition(100,position.y+100);
}


void ShowTask::draw(sf::RenderWindow& window) const
{
	window.draw(dateText);
	window.draw(taskText);
	createTaskButton.draw(window);
	deleteTaskButton.draw(window);
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
