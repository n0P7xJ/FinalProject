#include "ShowTask.h"


ShowTask::ShowTask(const sf::Vector2f& size, const sf::Vector2f& position) :
	createTaskButton(sf::Vector2f(130, 40), sf::Vector2f(position.x + (-280), position.y + 110), "Create task"),
	deleteTaskButton(sf::Vector2f(130, 40), sf::Vector2f(position.x + (-140), position.y + 110), "Delete Task"),
	upButton(sf::Vector2f(40, 40), sf::Vector2f(position.x + (- 340), position.y + 200), "/\\"),
	downButton(sf::Vector2f(40, 40), sf::Vector2f(position.x + (-340), position.y + 250), "\\/")
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
	inSetRectanglesTwo(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 290), sf::Color::Transparent);
	inSetRectanglesThree(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 350), sf::Color::Transparent);
	inSetRectanglesFour(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 410), sf::Color::Transparent);
	inSetRectanglesFive(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 470), sf::Color::Transparent);
	inSetRectanglesSix(sf::Vector2f(840, 40), sf::Vector2f(position.x + (-250), position.y + 530), sf::Color::Transparent);
}


void ShowTask::draw(sf::RenderWindow& window) const
{
	window.draw(dateText);
	window.draw(taskText);
	//кнопки
	createTaskButton.draw(window);
	deleteTaskButton.draw(window);
	upButton.draw(window);
	downButton.draw(window);

	//прямокутник
	window.draw(rectangle);
	window.draw(inRectangle);
	window.draw(inRectangleTwo);
	window.draw(inRectangleThree);
	window.draw(inRectangleFour);
	window.draw(inRectangleFive);
	window.draw(inRectangleSix);
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
	// Створення прямокутника 1
	inRectangle.setSize(size);
	inRectangle.setPosition(position);
	inRectangle.setFillColor(fillColor);
	// Налаштування коліру вздовж ліній прямокутника
	inRectangle.setOutlineColor(sf::Color::White);
	inRectangle.setOutlineThickness(2.0f);
}

void ShowTask::inSetRectanglesTwo(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{
	// Створення прямокутника 2 
	inRectangleTwo.setSize(size);
	inRectangleTwo.setPosition(position);
	inRectangleTwo.setFillColor(fillColor);
	inRectangleTwo.setOutlineColor(sf::Color::White);
	inRectangleTwo.setOutlineThickness(2.0f);
}

void ShowTask::inSetRectanglesThree(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{
	// Створення прямокутника 3
	inRectangleThree.setSize(size);
	inRectangleThree.setPosition(position);
	inRectangleThree.setFillColor(fillColor);
	inRectangleThree.setOutlineColor(sf::Color::White);
	inRectangleThree.setOutlineThickness(2.0f);

}

void ShowTask::inSetRectanglesFour(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{
	// Створення прямокутника 4
	inRectangleFour.setSize(size);
	inRectangleFour.setPosition(position);
	inRectangleFour.setFillColor(fillColor);
	inRectangleFour.setOutlineColor(sf::Color::White);
	inRectangleFour.setOutlineThickness(2.0f);

}

void ShowTask::inSetRectanglesFive(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{

	// Створення прямокутника 5
	inRectangleFive.setSize(size);
	inRectangleFive.setPosition(position);
	inRectangleFive.setFillColor(fillColor);
	inRectangleFive.setOutlineColor(sf::Color::White);
	inRectangleFive.setOutlineThickness(2.0f);
}
void ShowTask::inSetRectanglesSix(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color fillColor)
{

	// Створення прямокутника 6
	inRectangleSix.setSize(size);
	inRectangleSix.setPosition(position);
	inRectangleSix.setFillColor(fillColor);
	inRectangleSix.setOutlineColor(sf::Color::White);
	inRectangleSix.setOutlineThickness(2.0f);
}


bool ShowTask::pressCreateButton(sf::Vector2f mousePosition) const
{
	return createTaskButton.checkPress(mousePosition);
}

bool ShowTask::pressDeleteButton(sf::Vector2f mousePosition) const
{
	return deleteTaskButton.checkPress(mousePosition);
}

