#include "ShowTask.h"


ShowTask::ShowTask(const sf::Vector2f& size, const sf::Vector2f& position) : TextBox(size, position), 
createTaskButton(sf::Vector2f(130, 40), sf::Vector2f(250, 110), "Create task"),
deleteTaskButton(sf::Vector2f(130, 40), sf::Vector2f(390, 110), "Delete Task")
{
	dateText.setFont(defaultFontText);
	dateText.setCharacterSize(35);
	dateText.setFillColor(sf::Color::Black);
	dateText.setPosition(position);

}


void ShowTask::draw(sf::RenderWindow& window) const
{
	window.draw(dateText);
	createTaskButton.draw(window);
	deleteTaskButton.draw(window);
}

void ShowTask::setTaskInfo(const std::string& month, int day, int year)
{
	//інформація про день, місяць і рік
	std::string taskInfo = std::to_string(day) + " " + month + " " + std::to_string(year);

   //для виведення
	dateText.setString(taskInfo);
}
