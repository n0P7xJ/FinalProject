#include "SideMenu.h"

SideMenu::SideMenu(const sf::Vector2f& size, const sf::Vector2f& position) : isVisible(false)
{
	RectMenu.setSize(size);
	RectMenu.setPosition(position);
	RectMenu.setFillColor(sf::Color(46, 139, 87));
}

void SideMenu::Visible()
{
	isVisible = !isVisible; 
}

void SideMenu::draw(sf::RenderWindow& sideWindow)
{
	if (isVisible)
	{
		sideWindow.draw(RectMenu);
	}
}

void SideMenu::setBackground(const string& bg)
{
	if (!backgroundTexture.loadFromFile(bg))
	{
		cout << "немає текстури: " << bg << endl;
		return;
	}

	RectMenu.setTexture(&backgroundTexture);
}
